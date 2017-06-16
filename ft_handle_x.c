/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 14:46:24 by kzeng             #+#    #+#             */
/*   Updated: 2016/12/18 14:46:25 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_handle_hash_blank(char *str, t_list *list, int before)
{
	list->i = 0;
	if (before == 1)
	{
		while (ft_isxdigit(str[list->i]) == 0)
			list->i++;
		str[list->i - 1] = 'x';
		str[list->i - 2] = '0';
	}
	else
	{
		while (str[list->i] != ' ')
			list->i++;
		list->i++;
		while (list->i > 1)
		{
			str[list->i] = str[list->i - 2];
			str[list->i - 2] = ' ';
			list->i--;
		}
		str[0] = '0';
		str[1] = 'x';
	}
}

static char	*ft_handle_hash_noblank(char *str, t_list *list)
{
	char	*tmp;

	list->i = 0;
	if (list->zero == 1)
	{
		while (str[list->i] != '0' && str[list->i] != ' ')
			list->i++;
		str[list->i] = '0';
		str[list->i + 1] = 'x';
	}
	else if (list->zero != 1)
	{
		list->j = 0;
		tmp = str;
		str = (char *)malloc(ft_strlen(tmp) + 3);
		str[ft_strlen(tmp) + 2] = '\0';
		str[list->i++] = '0';
		str[list->i++] = 'x';
		while (tmp[list->j] != '\0')
			str[list->i++] = tmp[list->j++];
		free(tmp);
	}
	return (str);
}

static char	*ft_handle_hash_helper(char *str, t_list *list)
{
	list->i = 0;
	while (str[list->i] != '\0')
	{
		if (str[list->i] == ' ' && list->digit == 0)
			list->blankb = 1;
		if (str[list->i] == ' ')
			list->blank = 1;
		if (list->precision == -1 && list->digit == 0 &&
			((str[list->i] == ' ' || str[list->i] == '0') &&
			str[list->i + 1] == '0'))
			list->zero = 1;
		if (ft_isxdigit(str[list->i]) == 1)
			list->digit = 1;
		list->i++;
	}
	if (list->blankb == 1)
		ft_handle_hash_blank(str, list, 1);
	else if (list->blank == 1)
		ft_handle_hash_blank(str, list, 0);
	else if (list->blank == 0)
		str = ft_handle_hash_noblank(str, list);
	return (str);
}

static void	ft_print(char *str, t_list *list)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 70 &&
			(list->spec == 'x' || list->spec == 'p'))
			str[i] += 32;
		if (str[i] == 'x' && list->spec == 'X')
			str[i] = 'X';
		i++;
	}
	ft_putstr(str);
}

int			ft_handle_x(t_list *list, uintmax_t n)
{
	char	*str;

	str = ft_uitoa_base(n, 16);
	str = ft_handle_int_precision(str, list);
	if (list->precision == 0 && n == 0)
	{
		free(str);
		str = ft_strnew(2);
	}
	str = ft_handle_int_width(str, list);
	if (list->flags[4] == '0' && list->precision == -1 && list->flags[0] != '-')
		str = ft_handle_int_zero(str, list);
	if (list->flags[3] == '#' || list->spec == 'p')
	{
		list->i = 0;
		while (str[list->i] != '\0' && ft_isxdigit(str[list->i]) == 0)
			list->i++;
		if (str[list->i] != '\0' && n != 0)
			str = ft_handle_hash_helper(str, list);
	}
	ft_print(str, list);
	list->len = ft_strlen(str);
	free(str);
	return (list->len);
}
