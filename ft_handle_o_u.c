/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_o_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 17:08:36 by kzeng             #+#    #+#             */
/*   Updated: 2016/12/30 17:08:37 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_handle_o(t_list *list, uintmax_t num)
{
	char	*str;

	str = ft_uitoa_base(num, 8);
	str = ft_handle_int_precision(str, list);
	if (list->precision == 0 && num == 0)
	{
		free(str);
		str = ft_strnew(1);
	}
	str = ft_handle_int_width(str, list);
	if (list->flags[4] == '0' && list->precision == -1 && list->flags[0] != '-')
		str = ft_handle_int_zero(str, list);
	if (list->flags[3] == '#')
		str = ft_handle_int_hash(str, list);
	ft_putstr(str);
	list->len = ft_strlen(str);
	free(str);
	return (list->len);
}

static int	ft_handle_u(t_list *list, uintmax_t num)
{
	char	*str;

	str = ft_uitoa_base(num, 10);
	str = ft_handle_int_precision(str, list);
	if (list->precision == 0 && num == 0)
	{
		free(str);
		str = ft_strnew(1);
	}
	str = ft_handle_int_width(str, list);
	if (list->flags[4] == '0' && list->precision == -1 && list->flags[0] != '-')
		str = ft_handle_int_zero(str, list);
	ft_putstr(str);
	list->len = ft_strlen(str);
	free(str);
	return (list->len);
}

int			ft_handle_o_u(t_list *list, uintmax_t num)
{
	if (list->spec == 'o' || list->spec == 'O')
		return (ft_handle_o(list, num));
	else
		return (ft_handle_u(list, num));
}
