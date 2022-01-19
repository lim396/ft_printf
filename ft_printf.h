#ifndef	FT_PRINTF_H
# define FT_PRINTF_H


#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

typedef struct	s_order
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

t_order	init_order(void);
size_t parse(const char *fmt, size_t i, va_list args, t_order *order);
int conversion_print(char type, int counted, va_list args, t_order *order);
int ft_vsprintf(const char *fmt, va_list args);

int print_char(char c, int counted, t_order *order);
int print_str(const char *str, int counted, t_order *order);
int print_unsigned(size_t num, int counted, int base, t_order *order);
int	print_signed(int num, int counted, t_order *order);

int	parse_flags(const char *fmt, size_t i, t_order *order);
int parse_width(const char *fmt, size_t i, va_list args, t_order *order);
int	parse_precision(const char *fmt, size_t i, va_list args, t_order *order);

int count_digit(size_t num, size_t base);
int print_preci_and_arg_zero(int counted, int print_len, t_order *order);
int	print_s_conversion(int num, int figure_len, t_order *order);
int	print_u_conversion(size_t num, size_t base, int figure_len, t_order *order);
int	singed_will_print_len(int figure_len, int num, t_order *order);
int	unsigned_will_print_len(int figure_len, t_order *order);
size_t	ft_abs(long long num);

char	*reserve_mem(int *figure_len, t_order *order);
char	*add_precision(char *numstr, int num_len, t_order *order);
void	print_sign_or_spc(int num, t_order *order);
void	print_prefix(t_order *order);

size_t	ft_strnlen(const char *str, size_t n);
void ft_putnstr(const char *s, size_t n);

int	ft_printf(const char *fmt, ...);

#endif
