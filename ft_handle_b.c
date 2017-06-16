/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:21:57 by kzeng             #+#    #+#             */
/*   Updated: 2016/12/23 17:21:59 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_handle_b(t_list *list, intmax_t num)
{
	char		*str;

	str = ft_itoa_base(num, 2);
	str = ft_handle_int_precision(str, list);
	if (list->precision == 0 && num == 0)
	{
		free(str);
		str = ft_strnew(1);
	}
	if ((list->diff = list->width - ft_strlen(str)) > 0)
		str = ft_handle_int_width(str, list);
	if (list->flags[4] == '0' && list->precision == -1 && list->flags[0] != '-')
		str = ft_handle_int_zero(str, list);
	if (list->flags[3] == '#')
		str = ft_handle_int_hash(str, list);
	ft_putstr(str);
	free(str);
	return (ft_strlen(str));
}
