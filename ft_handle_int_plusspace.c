/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int_plusspace.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 18:14:17 by kzeng             #+#    #+#             */
/*   Updated: 2016/12/28 18:14:18 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_handle_int_end(char *str, t_list *list)
{
	if (list->i == 0)
	{
		if (list->flags[1] == '+')
			str[0] = '+';
		else
			str[0] = ' ';
	}
	else if (list->flags[0] == '-')
	{
		if (list->flags[1] == '+')
			str[0] = '+';
		else
			str[0] = ' ';
	}
	else
	{
		if (list->flags[1] == '+')
			str[list->i - 1] = '+';
		else
			str[list->i - 1] = ' ';
	}
	return (str);
}

static void	ft_handle_int_blank(char *str, t_list *list, int before)
{
	if (before == 1)
	{
		while (ft_isxdigit(str[list->i]) == 0)
			list->i++;
		if (list->flags[1] == '+')
			str[list->i - 1] = '+';
		else
			str[list->i - 1] = ' ';
	}
	else
	{
		while (str[list->i] != ' ')
			list->i++;
		while (list->i > 0)
		{
			str[list->i] = str[list->i - 1];
			str[list->i - 1] = ' ';
			list->i--;
		}
		if (list->flags[1] == '+')
			str[0] = '+';
		else
			str[0] = ' ';
	}
}

static char	*ft_handle_int_noblank(char *str, t_list *list)
{
	char	*tmp;

	if (list->zero > 0 && (list->numiszero == 0 ||
		(list->numiszero == 1 && list->width > 1)))
	{
		while (str[list->i] != '0')
			list->i++;
		str[list->i] = list->flags[1] == '+' ? '+' : ' ';
	}
	else
	{
		tmp = str;
		str = (char *)malloc(ft_strlen(tmp) + 2);
		str[ft_strlen(tmp) + 1] = '\0';
		str[list->i++] = list->flags[1] == '+' ? '+' : ' ';
		while (tmp[list->j] != '\0')
			str[list->i++] = tmp[list->j++];
		free(tmp);
	}
	return (str);
}

static char	*ft_handle_int_before(char *str, t_list *list)
{
	list->i = 0;
	while (str[list->i] != '\0')
	{
		if (str[list->i] == ' ' && list->digit == 0)
			list->blankb = 1;
		if (str[list->i] == ' ')
			list->blank = 1;
		if (ft_isxdigit(str[list->i]) == 1)
			list->digit = 1;
		if (str[list->i] == '0' && list->precision == -1)
			list->zero++;
		list->i++;
	}
	list->i = 0;
	list->j = 0;
	if (list->blankb == 1)
		ft_handle_int_blank(str, list, 1);
	else if (list->blank == 1)
		ft_handle_int_blank(str, list, 0);
	else if (list->blank == 0)
		str = ft_handle_int_noblank(str, list);
	return (str);
}

char		*ft_handle_int_plusspace(char *str, t_list *list)
{
	list->blankb = 0;
	list->blank = 0;
	list->zero = 0;
	list->digit = 0;
	list->i = 0;
	while (str[list->i] != '\0' && ft_isxdigit(str[list->i]) == 0)
		list->i++;
	if (str[list->i] == '\0')
		str = ft_handle_int_end(str, list);
	else
		str = ft_handle_int_before(str, list);
	return (str);
}
