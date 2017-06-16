/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 14:06:22 by kzeng             #+#    #+#             */
/*   Updated: 2016/12/18 14:06:24 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_pow(uintmax_t value, int base)
{
	int		pow;

	pow = 0;
	while (value != 0)
	{
		value /= base;
		pow++;
	}
	pow--;
	return (pow);
}

char		*ft_uitoa_base(uintmax_t value, int base)
{
	char		*b;
	char		*nbr;
	int			p;
	uintmax_t	n;

	b = "0123456789ABCDEF";
	n = value;
	if (value == 0)
	{
		nbr = (char *)malloc(2);
		nbr[0] = '0';
		nbr[1] = '\0';
		return (nbr);
	}
	p = ft_pow(n, base);
	nbr = (char *)malloc(sizeof(char) * (p + 1 + 1));
	nbr[p + 1] = '\0';
	while (n != 0)
	{
		nbr[p--] = b[n % base];
		n /= base;
	}
	return (nbr);
}
