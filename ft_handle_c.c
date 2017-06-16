/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 19:15:04 by kzeng             #+#    #+#             */
/*   Updated: 2016/12/23 19:15:08 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_handle_c_precision(char *str, int argument, t_list *list)
{
	if (list->flags[0] == '-')
	{
		while (list->i < MIN(list->precision, 1) && list->spec == 'c')
			str[list->i++] = (char)argument;
		while (list->i < list->len)
			str[list->i++] = ' ';
		if (argument == 0 && list->spec == 'c')
		{
			ft_putchar(0);
			str[0] = ' ';
			str[list->i - 1] = '\0';
		}
	}
	else
	{
		while (list->i < list->len - 1)
			str[list->i++] = list->flags[4] == '0' ? '0' : ' ';
		str[list->i++] = (char)argument;
		if (argument == 0 && list->spec == 's')
			str[list->i - 1] = list->flags[4] == '0' ? '0' : ' ';
	}
	ft_putstr(str);
	if (argument == 0 && list->spec == 'c')
		ft_putchar(0);
}

static void	ft_handle_c_width(char *str, int argument, t_list *list)
{
	if (list->flags[0] == '-')
	{
		str[list->i++] = (char)argument;
		while (list->i < list->len)
			str[list->i++] = ' ';
		if (argument == 0 && list->spec == 'c')
		{
			ft_putchar(0);
			str[0] = ' ';
			str[list->i - 1] = '\0';
		}
	}
	else
	{
		while (list->i < list->len - 1)
			str[list->i++] = list->flags[4] == '0' ? '0' : ' ';
		str[list->i] = (char)argument;
		if (argument == 0 && list->spec == 's')
			str[list->i] = list->flags[4] == '0' ? '0' : ' ';
	}
	ft_putstr(str);
	if (argument == 0 && list->flags[0] != '-' && list->spec == 'c')
		ft_putchar(0);
}

static void	ft_handle_c_prec(char *str, int argument, t_list *list)
{
	while (list->i < list->len)
		str[list->i++] = (char)argument;
	if (argument == 0)
		ft_putchar(0);
	ft_putstr(str);
	if (argument == 0 && list->precision == 0)
		list->len++;
}

int			ft_handle_c(t_list *list, int argument)
{
	char	*str;

	list->i = 0;
	list->j = 0;
	list->len = 1;
	if (list->width > 0)
	{
		list->len = MAX(list->width, MIN(1, list->precision));
		str = ft_strnew(list->len);
		if (list->precision > -1)
			ft_handle_c_precision(str, argument, list);
		else
			ft_handle_c_width(str, argument, list);
		free(str);
	}
	else if (list->precision > -1)
	{
		list->len = MIN(list->precision, 1);
		str = ft_strnew(list->len);
		ft_handle_c_prec(str, argument, list);
		free(str);
	}
	else
		ft_putchar(argument);
	return (list->len);
}
