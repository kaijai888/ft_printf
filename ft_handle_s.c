/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 19:20:05 by kzeng             #+#    #+#             */
/*   Updated: 2016/12/23 19:20:06 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_handle_s_null(t_list *list, const char *argument)
{
	int		i;

	i = 0;
	if ((list->width == 0 && list->precision == -1) ||
		(list->wstar == 1 && argument == NULL))
	{
		if (argument == NULL)
		{
			ft_putstr(list->nullstr);
			return (6);
		}
		ft_putstr(argument);
		return (ft_strlen(argument));
	}
	if (argument == NULL)
	{
		if (list->pstar == 1)
		{
			while (i < list->precision)
				ft_putchar(list->nullstr[i++]);
			return (list->precision);
		}
		return (ft_handle_c(list, 0));
	}
	return (-1);
}

static void	ft_handle_s_precision(char *str, const char *argument, t_list *list)
{
	list->i = 0;
	list->j = 0;
	if (list->flags[0] == '-')
	{
		while (list->i < MIN(list->precision, ft_strlen(argument)))
		{
			str[list->i] = argument[list->i];
			list->i++;
		}
		while (list->i < list->len)
			str[list->i++] = ' ';
	}
	else
	{
		while (list->i < list->len - MIN(list->precision, ft_strlen(argument)))
		{
			if (list->flags[4] == '0')
				str[list->i++] = '0';
			else
				str[list->i++] = ' ';
		}
		while (list->j < list->precision)
			str[list->i++] = argument[list->j++];
	}
	ft_putstr(str);
}

static void	ft_handle_s_width(char *str, const char *argument, t_list *list)
{
	list->i = 0;
	if (list->flags[0] == '-')
	{
		while (list->i < ft_strlen(argument))
		{
			str[list->i] = argument[list->i];
			list->i++;
		}
		while (list->i < list->len)
			str[list->i++] = ' ';
	}
	else
	{
		while (list->i < list->len - ft_strlen(argument))
		{
			if (list->flags[4] == '0')
				str[list->i++] = '0';
			else
				str[list->i++] = ' ';
		}
		while (list->i < list->len)
			str[list->i++] = argument[list->j++];
	}
	ft_putstr(str);
}

int			ft_handle_s(t_list *list, const char *argument)
{
	char	*str;

	list->len = 0;
	if ((list->i = ft_handle_s_null(list, argument)) != -1)
		return (list->i);
	list->i = 0;
	if (list->width > 0)
	{
		list->len = MAX(list->width, MIN(ft_strlen(argument), list->precision));
		str = ft_strnew(list->len);
		if (list->precision > -1)
			ft_handle_s_precision(str, argument, list);
		else
			ft_handle_s_width(str, argument, list);
		free(str);
	}
	else if (list->precision > -1)
	{
		list->len = MIN(list->precision, ft_strlen(argument));
		while (list->i++ < list->len)
			ft_putchar(argument[list->i - 1]);
	}
	return (list->len);
}
