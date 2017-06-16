/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 22:25:13 by kzeng             #+#    #+#             */
/*   Updated: 2016/12/11 22:25:15 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		ft_pow(intmax_t value, int base)
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

static char		*ft_edge_zero(void)
{
	char	*str;

	str = (char *)malloc(2);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char			*ft_itoa_base(intmax_t value, int base)
{
	char		*b;
	char		*nbr;
	int			neg;
	int			p;
	intmax_t	n;

	b = "0123456789ABCDEF";
	neg = value < 0 && base == 10 ? 1 : 0;
	n = value;
	if (value == 0)
		return (ft_edge_zero());
	p = ft_pow(n, base);
	nbr = (char *)malloc(sizeof(char) * (p + neg + 1 + 1));
	nbr[p + neg + 1] = '\0';
	nbr[0] = neg == 1 && base == 10 ? '-' : ' ';
	while (n != 0)
	{
		nbr[p-- + neg] = n < 0 ? b[n % base * -1] : b[n % base];
		n /= base;
	}
	return (nbr);
}
