/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:07:55 by kzeng             #+#    #+#             */
/*   Updated: 2016/11/13 14:07:56 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**	char	flags[6];
**	flags[0] = '-';
**	flags[1] = '+';
**	flags[2] = ' ';
**	flags[3] = '#';
**	flags[4] = '0';
**	char	*length = "hh, h, l, ll, j, z";
**	char	*type = "%sSpdDioOuUxXcCb";
**
**	%i synonym for %d
**	%D same as %ld (long decimal)
**	%U same as %lu (long unsigned decimal)
**	%O same as %lo (long octal)
**	%F same as %f
*/

char	*ft_findflags(const char *format, int i, int digit, char spec)
{
	char	*flags;

	flags = ft_strdup("xxxxx");
	while (format[i] != spec && format[i] != '.')
	{
		if (ft_isxdigit(format[i]) == 1 && format[i] != '0')
			digit = 1;
		else if (format[i] == '-')
			flags[0] = '-';
		else if (format[i] == '+')
			flags[1] = '+';
		else if (format[i] == ' ')
			flags[2] = ' ';
		else if (format[i] == '#')
			flags[3] = '#';
		else if (format[i] == '0' && digit == 0)
			flags[4] = '0';
		i++;
	}
	if (flags[0] == '-')
		flags[4] = '\0';
	if (flags[1] == '+')
		flags[2] = '\0';
	return (flags);
}

char	*ft_findlength(const char *format, int i, char spec)
{
	while (format[i] != spec)
	{
		if (format[i] == 'h' && format[i + 1] == 'h')
			return ("hh");
		else if (format[i] == 'h')
			return ("h");
		else if (format[i] == 'l' && format[i + 1] == 'l')
			return ("ll");
		else if (format[i] == 'l')
			return ("l");
		else if (format[i] == 'j')
			return ("j");
		else if (format[i] == 'z')
			return ("z");
		i++;
	}
	return (NULL);
}

char	ft_findspec(const char *format, int i)
{
	char	*s;
	int		j;
	int		alpha;

	s = "%sSpdDioOuUxXcCb";
	alpha = 0;
	while (format[i] != '\0' && alpha == 0)
	{
		j = 0;
		if (ft_isalpha(format[i]) == 1 && format[i] != 'h' && format[i] != 'l'
			&& format[i] != 'j' && format[i] != 'z')
			alpha = 1;
		while (j < 16)
		{
			if (format[i] == s[j])
				return (s[j]);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_handler(va_list *args, t_list *list)
{
	if (list->spec == '%')
		return (ft_handle_percent(list));
	else if (list->spec == 'S' ||
		(list->spec == 's' && ft_strcmp(list->length, "l") == 0))
		return (ft_handle_ls(list, va_arg(*args, wchar_t *)));
	else if (list->spec == 's')
		return (ft_handle_s(list, va_arg(*args, char *)));
	else if (list->spec == 'p')
		return (ft_handle_p(list, va_arg(*args, void *)));
	else if (list->spec == 'd' || list->spec == 'D' || list->spec == 'i')
		return (ft_handle_d_i(list, ft_handle_int_type(args, list)));
	else if (list->spec == 'o' || list->spec == 'O' ||
		list->spec == 'u' || list->spec == 'U')
		return (ft_handle_o_u(list, ft_handle_uint_type(args, list)));
	else if (list->spec == 'x' || list->spec == 'X')
		return (ft_handle_x(list, ft_handle_uint_type(args, list)));
	else if (list->spec == 'C' ||
		(list->spec == 'c' && ft_strcmp(list->length, "l") == 0))
		return (ft_handle_lc(list, va_arg(*args, wint_t)));
	else if (list->spec == 'c')
		return (ft_handle_c(list, va_arg(*args, int)));
	else
		return (ft_handle_b(list, ft_handle_int_type(args, list)));
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	t_list		*list;
	int			i;

	va_start(args, format);
	list = (t_list *)malloc(sizeof(t_list));
	i = 0;
	list->total = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			i = ft_help(list, &args, format, i);
		else
		{
			ft_putchar(format[i]);
			list->total++;
		}
		i++;
	}
	va_end(args);
	free(list);
	return (list->total);
}
