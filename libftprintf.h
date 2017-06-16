/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzeng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 14:06:44 by kzeng             #+#    #+#             */
/*   Updated: 2016/11/13 14:07:34 by kzeng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# define MAX(x, y) (x > y ? x : y)
# define MIN(x, y) (x > y ? y : x)

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>
# include <wchar.h>
# include <locale.h>
# include <stddef.h>

typedef struct	s_list
{
	int			total;
	char		*flags;
	int			width;
	int			precision;
	char		*length;
	char		spec;
	int			astar;
	int			bstar;
	int			wstar;
	int			pstar;
	int			num;
	int			i;
	int			j;
	int			len;
	int			diff;
	int			blankb;
	int			blank;
	int			zero;
	int			digit;
	int			neg;
	int			numiszero;
	char		*nullstr;
	int			wchar_bytes;
}				t_list;

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isxdigit(int c);
char			*ft_itoa_base(intmax_t value, int base);
long long		ft_power(int x, int n);
void			ft_putchar(char c);
void			ft_putnbr(int nb);
void			ft_putstr(const char *s);
int				ft_strcmp(char *s1, char *s2);
char			*ft_strdup(const char *s1);
int				ft_strlen(const char *str);
char			*ft_strnew(size_t size);
char			*ft_uitoa_base(uintmax_t value, int base);

int				ft_printf(const char *format, ...);
int				ft_help(t_list *list, va_list *args, const char *format, int i);
void			ft_initialize(t_list **list);
char			ft_findspec(const char *format, int i);
int				ft_no_spec(t_list *list, const char *format, int i);
char			*ft_findflags(const char *format, int i, int digit, char spec);
char			*ft_findlength(const char *format, int i, char spec);
int				ft_handler(va_list *args, t_list *list);

intmax_t		ft_handle_int_type(va_list *args, t_list *list);
uintmax_t		ft_handle_uint_type(va_list *args, t_list *list);

int				ft_handle_percent(t_list *list);
int				ft_handle_s(t_list *list, const char *argument);
int				ft_handle_ls(t_list *list, wchar_t *wchar);
int				ft_handle_p(t_list *list, void *argument);
int				ft_handle_d_i(t_list *list, intmax_t n);
int				ft_handle_o_u(t_list *list, uintmax_t n);
int				ft_handle_x(t_list *list, uintmax_t n);
int				ft_handle_c(t_list *list, int argument);
int				ft_handle_lc(t_list *list, wint_t wint);
int				ft_handle_b(t_list *list, intmax_t n);

char			*ft_handle_int_negative(char *str, t_list *list);
char			*ft_handle_int_precision(char *str, t_list *list);
char			*ft_handle_int_width(char *str, t_list *list);
char			*ft_handle_int_zero(char *str, t_list *list);
char			*ft_handle_int_plusspace(char *str, t_list *list);
char			*ft_handle_int_hash(char *str, t_list *list);

#endif
