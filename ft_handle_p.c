/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 19:14:21 by kzeng             #+#    #+#             */
/*   Updated: 2016/12/23 19:14:22 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_handle_p_diff(t_list *list, int diff, uintmax_t num)
{
	int	d;

	if (list->flags[0] == '-' || list->flags[4] == '0')
	{
		ft_putstr("0x");
		if (list->flags[4] == '0')
		{
			list->width = diff + 1;
			return (ft_handle_x(list, num) + 2);
		}
		list->width = list->precision == -1 ? diff + 1 : diff + list->precision;
		return (ft_handle_x(list, num) + 2);
	}
	else
	{
		d = diff;
		while (d-- > 0)
			ft_putchar(' ');
		ft_putstr("0x");
		list->width = 0;
		return (ft_handle_x(list, num) + 2 + diff);
	}
}

int		ft_handle_p(t_list *list, void *argument)
{
	int	diff;

	if (list->precision >= 0 && list->width == 0)
	{
		ft_putstr("0x");
		return (ft_handle_x(list, (uintmax_t)argument) + 2);
	}
	if ((uintmax_t)argument == 0)
	{
		if (list->precision == -1)
			diff = list->width - 3;
		else if (list->precision == 0)
			diff = list->width - 2;
		else
			diff = list->width - list->precision - 2;
		if (diff > 0)
			return (ft_handle_p_diff(list, diff, (uintmax_t)argument));
		ft_putstr("0x");
		list->width -= 2;
		return (ft_handle_x(list, (uintmax_t)argument) + 2);
	}
	if (list->precision == -1)
		list->width -= 2;
	return (ft_handle_x(list, (uintmax_t)argument));
}
