/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_ls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 19:25:10 by kzeng             #+#    #+#             */
/*   Updated: 2016/12/23 19:25:11 by kzeng            ###   ########.fr       */
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

static void	ft_store_bytes(char *str, t_list *list, int byt, wchar_t *wchar)
{
	if (list->wchar_bytes - list->i < byt)
		list->i++;
	else if (byt == 1)
		str[list->i++] = *wchar;
	else if (byt == 2)
	{
		str[list->i++] = (*wchar >> 6) + 0xC0;
		str[list->i++] = (*wchar & 0x3F) + 0x80;
	}
	else if (byt == 3)
	{
		str[list->i++] = (*wchar >> 12) + 0xE0;
		str[list->i++] = ((*wchar >> 6) & 0x3F) + 0x80;
		str[list->i++] = (*wchar & 0x3F) + 0x80;
	}
	else
	{
		str[list->i++] = (*wchar >> 18) + 0xF0;
		str[list->i++] = ((*wchar >> 12) & 0x3F) + 0x80;
		str[list->i++] = ((*wchar >> 6) & 0x3F) + 0x80;
		str[list->i++] = (*wchar & 0x3F) + 0x80;
	}
}

static void	ft_loop(char *str, t_list *list, wchar_t *wchar)
{
	int		bytes;

	while (list->i < list->wchar_bytes)
	{
		bytes = ft_char_bytes(*wchar);
		ft_store_bytes(str, list, bytes, wchar);
		wchar++;
	}
}

int			ft_handle_ls(t_list *list, wchar_t *wchar)
{
	int		wchar_len;
	wchar_t	*copy;
	char	*str;

	wchar_len = 0;
	list->wchar_bytes = 0;
	copy = wchar;
	if (wchar == NULL)
		return (ft_handle_s(list, NULL));
	while (wchar[wchar_len] != '\0')
		wchar_len++;
	while (wchar_len > 0)
	{
		list->wchar_bytes += ft_char_bytes(*wchar);
		wchar++;
		wchar_len--;
	}
	if (list->precision > -1)
		list->wchar_bytes = MIN(list->wchar_bytes, list->precision);
	wchar = copy;
	str = (char *)malloc(sizeof(char) * (list->wchar_bytes + 1));
	str[list->wchar_bytes] = '\0';
	ft_loop(str, list, wchar);
	return (ft_handle_s(list, str));
}
