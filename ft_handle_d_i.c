/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_d_i.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 12:46:35 by kzeng             #+#    #+#             */
/*   Updated: 2016/12/18 12:46:36 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_handle_d_i(t_list *list, intmax_t n)
{
	char		*str;

	str = ft_itoa_base(n, 10);
	if (n < 0)
		list->neg = 1;
	if (n == 0)
		list->numiszero = 1;
	if ((list->diff = list->precision - ft_strlen(str) + list->neg) > 0)
		str = ft_handle_int_negative(str, list);
	if (list->precision == 0 && n == 0)
	{
		free(str);
		str = ft_strnew(1);
	}
	str = ft_handle_int_width(str, list);
	if (list->flags[4] == '0' && list->precision == -1 && list->flags[0] != '-')
		str = ft_handle_int_zero(str, list);
	if ((list->flags[1] == '+' || list->flags[2] == ' ') && n >= 0)
		str = ft_handle_int_plusspace(str, list);
	ft_putstr(str);
	free(str);
	return (ft_strlen(str));
}
