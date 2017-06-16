/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int_hash.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 18:57:24 by kzeng             #+#    #+#             */
/*   Updated: 2016/12/26 18:57:26 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_handle_int_hash_blankb(char *str, t_list *list)
{
	list->i = 0;
	while (ft_isxdigit(str[list->i]) == 0)
		list->i++;
	str[list->i - 1] = '0';
}

static void	ft_handle_int_hash_blank(char *str, t_list *list)
{
	list->i = 0;
	while (str[list->i] != ' ')
		list->i++;
	while (list->i > 0)
	{
		str[list->i] = str[list->i - 1];
		str[list->i - 1] = ' ';
		list->i--;
	}
	str[0] = '0';
}

static char	*ft_handle_int_hash_noblank(char *str, t_list *list)
{
	char	*tmp;

	list->i = 0;
	if (list->zero != 1)
	{
		list->j = 0;
		tmp = str;
		str = (char *)malloc(ft_strlen(tmp) + 2);
		str[ft_strlen(tmp) + 1] = '\0';
		str[list->i++] = '0';
		while (tmp[list->j] != '\0')
			str[list->i++] = tmp[list->j++];
		free(tmp);
	}
	return (str);
}

static char	*ft_handle_int_hash_helper(char *str, t_list *list)
{
	list->i = 0;
	while (str[list->i] != '\0')
	{
		if (str[list->i] == ' ' && list->digit == 0)
			list->blankb = 1;
		if (str[list->i] == ' ')
			list->blank = 1;
		if (str[list->i] == '0' && list->digit == 0)
			list->zero = 1;
		if (ft_isxdigit(str[list->i]) == 1)
			list->digit = 1;
		list->i++;
	}
	if (list->blankb == 1)
		ft_handle_int_hash_blankb(str, list);
	else if (list->blank == 1)
		ft_handle_int_hash_blank(str, list);
	else if (list->blank == 0)
		str = ft_handle_int_hash_noblank(str, list);
	return (str);
}

char		*ft_handle_int_hash(char *str, t_list *list)
{
	list->blankb = 0;
	list->blank = 0;
	list->zero = 0;
	list->digit = 0;
	list->i = 0;
	while (str[list->i] != '\0' && ft_isxdigit(str[list->i]) == 0)
		list->i++;
	if (str[list->i] == '\0')
	{
		if (list->i == 0 || list->flags[0] == '-')
			str[0] = '0';
		else
			str[list->i - 1] = '0';
	}
	else
		str = ft_handle_int_hash_helper(str, list);
	return (str);
}
