/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 19:26:26 by kzeng             #+#    #+#             */
/*   Updated: 2016/12/23 19:26:27 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_handle_percent(t_list *list)
{
	list->i = 0;
	if (list->width > 1)
	{
		list->len = list->width;
		if (list->flags[0] == '-')
		{
			ft_putchar('%');
			while (list->i++ + 1 < list->len)
				ft_putchar(' ');
		}
		else
		{
			while (list->i++ < list->len - 1)
			{
				if (list->flags[4] == '0')
					ft_putchar('0');
				else
					ft_putchar(' ');
			}
			ft_putchar('%');
		}
		return (list->len);
	}
	ft_putchar('%');
	return (1);
}
