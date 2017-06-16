/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_lc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 19:23:43 by kzeng             #+#    #+#             */
/*   Updated: 2016/12/23 19:23:44 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_char_bytes(wchar_t wchar)
{
	if (wchar <= 0x7f)
		return (1);
	else if (wchar <= 0x7ff)
		return (2);
	else if (wchar <= 0xffff)
		return (3);
	else
		return (4);
}

static void	ft_store_bytes(char *str, t_list *list, int bytes, wint_t wint)
{
	list->i = 0;
	while (list->i < list->wchar_bytes)
	{
		bytes = ft_char_bytes((wchar_t)wint);
		if (bytes == 1)
			str[list->i++] = (wchar_t)wint;
		else if (bytes == 2)
		{
			str[list->i++] = ((wchar_t)wint >> 6) + 0xC0;
			str[list->i++] = ((wchar_t)wint & 0x3F) + 0x80;
		}
		else if (bytes == 3)
		{
			str[list->i++] = ((wchar_t)wint >> 12) + 0xE0;
			str[list->i++] = (((wchar_t)wint >> 6) & 0x3F) + 0x80;
			str[list->i++] = ((wchar_t)wint & 0x3F) + 0x80;
		}
		else
		{
			str[list->i++] = ((wchar_t)wint >> 18) + 0xF0;
			str[list->i++] = (((wchar_t)wint >> 12) & 0x3F) + 0x80;
			str[list->i++] = (((wchar_t)wint >> 6) & 0x3F) + 0x80;
			str[list->i++] = ((wchar_t)wint & 0x3F) + 0x80;
		}
	}
}

int			ft_handle_lc(t_list *list, wint_t wint)
{
	char	*str;

	list->wchar_bytes = 0;
	if (wint == 0)
		return (ft_handle_c(list, 0));
	list->wchar_bytes += ft_char_bytes((wchar_t)wint);
	str = (char *)malloc(sizeof(char) * (list->wchar_bytes + 1));
	str[list->wchar_bytes] = '\0';
	ft_store_bytes(str, list, 0, wint);
	return (ft_handle_s(list, str));
}
