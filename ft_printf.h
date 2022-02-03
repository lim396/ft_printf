/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 23:03:30 by shongou           #+#    #+#             */
/*   Updated: 2022/01/31 23:03:31 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <string.h>
# include <ctype.h>
# include "libft/libft.h"

typedef struct s_order
{
	int		left;
	int		zero;
	int		hash;
	int		plus;
	int		spc;
	int		width;
	int		precision;
	char	type;
}	t_order;

int		print_ordinary_char(const char *fmt, size_t i, int *count);
size_t	parse(const char *fmt, size_t i, va_list ap, t_order *order);
int		conversion_print(char type, int count, va_list ap, t_order *order);
int		ft_vsprintf(const char *fmt, va_list ap);

int		print_char(char c, int counted, t_order *order);
int		print_str(const char *str, int counted, t_order *order);
int		print_unsigned(size_t n, int counted, int base, t_order *order);
int		print_signed(int n, int counted, t_order *order);

t_order	init_order(void);
int		parse_flags(const char *fmt, size_t i, t_order *order);
int		parse_width(const char *fmt, size_t i, va_list ap, t_order *order);
int		parse_precision(const char *fmt, size_t i, va_list ap, t_order *order);

int		count_digit(size_t n, size_t base);
int		print_prefix_or_sign(int counted, int print_len, t_order *order);
int		convert_print_s(int n, int figure_len, t_order *order);
int		convert_print_u(size_t n, size_t base, int figure_len, t_order *order);
int		singed_will_print_len(int figure_len, int n, t_order *order);
int		unsigned_will_print_len(int figure_len, size_t n, t_order *order);
size_t	ft_abs(long long n);

char	*reserve_mem(int *figure_len, t_order *order);
char	*add_precision(char *numstr, t_order *order);
void	print_sign_or_spc(int n, t_order *order);
void	print_prefix(t_order *order);

size_t	ft_strnlen(const char *str, size_t n);
void	ft_putnstr(const char *s, size_t n);

int		ft_printf(const char *fmt, ...);

#endif
