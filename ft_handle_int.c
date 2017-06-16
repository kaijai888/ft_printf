/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 17:31:56 by kzeng             #+#    #+#             */
/*   Updated: 2016/12/26 17:31:57 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ft_handle_int_precision(char *str, t_list *list)
{
	char	*tmp;

	list->i = 0;
	list->j = 0;
	if ((list->diff = list->precision - ft_strlen(str)) > 0)
	{
		tmp = str;
		str = (char *)malloc(list->precision + 1);
		str[list->precision] = '\0';
		while (list->diff > 0)
		{
			str[list->i++] = '0';
			list->diff--;
		}
		while (tmp[list->j] != '\0')
			str[list->i++] = tmp[list->j++];
		free(tmp);
	}
	return (str);
}

static void	ft_handle_int_position(char *str, char *tmp, t_list *list, int left)
{
	if (left == 1)
	{
		while (tmp[list->i] != '\0')
		{
			str[list->i] = tmp[list->i];
			list->i++;
		}
		while (list->diff > 0)
		{
			str[list->i++] = ' ';
			list->diff--;
		}
	}
	else
	{
		while (list->diff > 0)
		{
			str[list->i++] = ' ';
			list->diff--;
		}
		while (tmp[list->j] != '\0')
			str[list->i++] = tmp[list->j++];
	}
}

char		*ft_handle_int_width(char *str, t_list *list)
{
	char	*tmp;

	if ((list->diff = list->width - ft_strlen(str)) > 0)
	{
		list->i = 0;
		list->j = 0;
		tmp = str;
		str = (char *)malloc(list->width + 1);
		str[list->width] = '\0';
		if (list->flags[0] == '-')
			ft_handle_int_position(str, tmp, list, 1);
		else
			ft_handle_int_position(str, tmp, list, 0);
		free(tmp);
	}
	return (str);
}

char		*ft_handle_int_zero(char *str, t_list *list)
{
	list->i = 0;
	while (str[list->i] != '\0' && ft_isxdigit(str[list->i]) == 0)
	{
		if (str[list->i] == ' ')
			str[list->i] = '0';
		if (str[list->i] == '-')
		{
			str[list->i] = '0';
			str[0] = '-';
		}
		list->i++;
	}
	return (str);
}

char		*ft_handle_int_negative(char *str, t_list *list)
{
	char	*tmp;

	list->i = 0;
	tmp = str;
	str = (char *)malloc(list->precision + list->neg + 1);
	str[list->precision + list->neg] = '\0';
	if (list->neg == 1)
		str[list->i++] = '-';
	while (list->diff > 0)
	{
		str[list->i++] = '0';
		list->diff--;
	}
	while (tmp[list->neg] != '\0')
		str[list->i++] = tmp[list->neg++];
	free(tmp);
	return (str);
}
