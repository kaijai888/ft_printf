/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 17:31:15 by kzeng             #+#    #+#             */
/*   Updated: 2016/12/30 17:31:16 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_initialize(t_list **list)
{
	(*list)->flags = 0;
	(*list)->width = 0;
	(*list)->precision = 0;
	(*list)->length = 0;
	(*list)->spec = 0;
	(*list)->astar = 0;
	(*list)->bstar = 0;
	(*list)->wstar = 0;
	(*list)->pstar = 0;
	(*list)->num = 0;
	(*list)->i = 0;
	(*list)->j = 0;
	(*list)->len = 0;
	(*list)->diff = 0;
	(*list)->blankb = 0;
	(*list)->blank = 0;
	(*list)->zero = 0;
	(*list)->digit = 0;
	(*list)->neg = 0;
	(*list)->numiszero = 0;
	(*list)->nullstr = "(null)";
	(*list)->wchar_bytes = 0;
}

intmax_t	ft_handle_int_type(va_list *args, t_list *list)
{
	intmax_t	n;

	n = va_arg(*args, intmax_t);
	if (list->spec == 'D' || (ft_strcmp(list->length, "l") == 0))
		n = (long)n;
	else if (ft_strcmp(list->length, "hh") == 0)
		n = (char)n;
	else if (ft_strcmp(list->length, "h") == 0)
		n = (short)n;
	else if (ft_strcmp(list->length, "ll") == 0)
		n = (long long)n;
	else if (list->spec == 'b' || ft_strcmp(list->length, "j") == 0)
		n = (intmax_t)n;
	else if (ft_strcmp(list->length, "z") == 0)
		n = (size_t)n;
	else
		n = (int)n;
	return (n);
}

uintmax_t	ft_handle_uint_type(va_list *args, t_list *list)
{
	uintmax_t	n;

	n = va_arg(*args, uintmax_t);
	if (list->spec == 'O' || list->spec == 'U' ||
		(ft_strcmp(list->length, "l") == 0))
		n = (unsigned long)n;
	else if (ft_strcmp(list->length, "hh") == 0)
		n = (unsigned char)n;
	else if (ft_strcmp(list->length, "h") == 0)
		n = (unsigned short)n;
	else if (ft_strcmp(list->length, "ll") == 0)
		n = (unsigned long long)n;
	else if (ft_strcmp(list->length, "j") == 0)
		n = (uintmax_t)n;
	else if (ft_strcmp(list->length, "z") == 0)
		n = (size_t)n;
	else
		n = (unsigned int)n;
	return (n);
}
