#include "ft_printf.h"

int	convert_print_s(int n, int figure_len, t_order *order)
{
	char			*numstr;
	int				write_len;
	unsigned int	num;

	numstr = reserve_mem(&figure_len, order);
	if (!numstr)
		return (-1);
	write_len = figure_len;
	if (n < 0 || order->plus || order->spc)
		print_sign_or_spc(n, order);
	numstr = add_precision(numstr, figure_len - order->precision, order);
	if (n == 0)
		numstr[--figure_len] = '0';
	if (n < 0)
		num = -(n + 1) + 1u;
	else
		num = n;
	while (num)
	{
		numstr[--figure_len] = "0123456789"[num % 10];
		num = num / 10;
	}
	write(1, numstr, write_len);
	free(numstr);
	return (0);
}

int	singed_will_print_len(int figure_len, int n, t_order *order)
{
	int	print_len;

	print_len = figure_len;
	if (order->plus || order->spc || n < 0)
		print_len += 1;
	while (print_len < order->width)
		print_len++;
	return (print_len);
}

size_t	ft_abs(long long n)
{
	if (n < 0)
		return (-(n + 1) + 1u);
	return (n);
}
