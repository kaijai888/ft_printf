/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_nospec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 18:43:59 by kzeng             #+#    #+#             */
/*   Updated: 2016/12/30 18:44:00 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_init(int *a, int *b, int *c, int *d)
{
	*a = 0;
	*b = 0;
	*c = 0;
	*d = 0;
}

static int	ft_blah1(int num, int flag_zero, char c)
{
	int	i;

	i = 0;
	while (--num > 0)
	{
		if (flag_zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		i++;
	}
	ft_putchar(c);
	return (i + 1);
}

static int	ft_blah2(int notzero, int num, char c, t_list *list)
{
	if (ft_isdigit(c) == 1 && notzero != 0)
	{
		if (notzero == 2)
			num = 0;
		if (num == 0)
			num = (c - '0');
		else if (num > 0)
		{
			num *= 10;
			num += (c - '0');
		}
	}
	else
	{
		if (c != ' ')
		{
			ft_putchar(c);
			list->len++;
		}
	}
	return (num);
}

int			ft_no_spec(t_list *list, const char *format, int i)
{
	int		alpha;
	int		num;
	int		notzero;
	int		flag_zero;

	list->len = 0;
	ft_init(&alpha, &num, &notzero, &flag_zero);
	while (format[i] != '\0')
	{
		if (format[i] == '0' && num == 0)
			flag_zero = 1;
		if (ft_isdigit(format[i]) == 1 && format[i] != '0' && notzero == 0 &&
			alpha == 0)
			notzero = 1;
		if (ft_isdigit(format[i]) == 1 && num > 0)
			notzero = 2;
		if (ft_isalpha(format[i]) == 1)
			alpha = 1;
		if (alpha == 1)
			list->len += ft_blah1(num, flag_zero, format[i++]);
		else
			num = ft_blah2(notzero, num, format[i++], list);
	}
	return (list->len);
}
