/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 17:31:21 by kzeng             #+#    #+#             */
/*   Updated: 2016/12/30 17:31:21 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_findwidth_helper(char c, t_list *list)
{
	if (c == '*')
	{
		list->wstar = 1;
		if (list->num == 0)
			list->bstar = 1;
		else
			list->astar = 1;
	}
	if (ft_isxdigit(c) == 1 && c != '0' && list->zero == 0)
		list->zero = 1;
	if (ft_isxdigit(c) == 0 && list->num > 0)
		list->zero = 2;
	if (ft_isxdigit(c) == 1 && list->zero != 0)
	{
		if (list->zero == 2)
			list->num = 0;
		if (list->num == 0)
			list->num = c - '0';
		else if (list->num > 0)
		{
			list->num *= 10;
			list->num += (c - '0');
		}
	}
}

int			ft_findwidth(const char *format, int i, va_list *args, t_list *list)
{
	int		star;

	list->num = 0;
	list->zero = 0;
	list->astar = 0;
	list->bstar = 0;
	star = 0;
	while (format[i] != list->spec && format[i] != '.')
		ft_findwidth_helper(format[i++], list);
	list->zero = 0;
	if (list->wstar == 1)
		star = va_arg(*args, int);
	if (list->astar == 1 || (list->bstar == 1 && list->num == 0))
	{
		if (star < 0)
		{
			list->flags[0] = '-';
			star *= -1;
		}
		return (star);
	}
	return (list->num);
}

static void	ft_findprec_helper(char c, t_list *list)
{
	if (c == '.')
		list->num = 0;
	if (c == '*')
	{
		if (list->j == 1)
			list->j--;
		else
		{
			list->j = 2;
			if (list->num == 0)
				list->bstar = 1;
			else
				list->astar = 1;
		}
	}
	if (ft_isxdigit(c) == 1 && list->num >= 0)
	{
		if (list->num == 0)
			list->num = c - '0';
		else if (list->num > 0)
		{
			list->num *= 10;
			list->num += (c - '0');
		}
	}
}

int			ft_findprec(const char *format, int i, va_list *args, t_list *list)
{
	int		star;

	list->astar = 0;
	list->bstar = 0;
	list->pstar = 0;
	list->num = -1;
	list->j = list->wstar == 1 ? 1 : 0;
	star = 0;
	while (format[i] != list->spec)
		ft_findprec_helper(format[i++], list);
	if (list->j == 2)
		star = va_arg(*args, int);
	if (list->astar == 1 || (list->bstar == 1 && list->num == 0))
	{
		list->pstar = 1;
		if (star < 0 && list->spec == 's')
			star *= -1;
		else if (star < 0)
			star = -1;
		return (star);
	}
	return (list->num);
}

int			ft_help(t_list *list, va_list *args, const char *format, int i)
{
	ft_initialize(&list);
	list->spec = ft_findspec(format, ++i);
	if (list->spec == 0)
	{
		list->total += ft_no_spec(list, format, i);
		while (format[i + 1] != '\0')
			i++;
	}
	else
	{
		list->flags = ft_findflags(format, i, 0, list->spec);
		list->width = ft_findwidth(format, i, args, list);
		list->precision = ft_findprec(format, i, args, list);
		list->length = ft_findlength(format, i, list->spec);
		list->total += ft_handler(args, list);
		while (format[i] != list->spec)
			i++;
		free(list->flags);
	}
	return (i);
}
