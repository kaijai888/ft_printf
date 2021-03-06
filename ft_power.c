/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 05:25:01 by kzeng             #+#    #+#             */
/*   Updated: 2016/12/17 05:25:05 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long long	ft_power(int x, int n)
{
	long long num;

	num = 1;
	if (n == 0)
		return (1);
	if (n < 0)
		return (0);
	while (n > 0)
	{
		num *= x;
		n--;
	}
	return (num);
}
