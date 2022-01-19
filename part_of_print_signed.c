#include "ft_printf.h"

int	print_s_conversion(int num, int figure_len, t_order *order)
{
	char			*numstr;
	int				write_len;
	unsigned int	n;
	
	numstr = reserve_mem(&figure_len, order);
	if (!numstr)
		return (-1);
	write_len = figure_len;
	if (num < 0 || order->plus || order->spc)
		print_sign_or_spc(num, order);
	numstr = add_precision(numstr, figure_len - order->precision, order);
	if (num == 0)
		numstr[--figure_len] = '0';
	if (num < 0)
		n = -(num + 1) + 1u;
	else
		n = num;
	while (n)
	{
		numstr[--figure_len] = "0123456789"[n % 10];
		n = n / 10;
	}
	write(1, numstr, write_len);
	free(numstr);
	return (0);
}

int	singed_will_print_len(int figure_len, int num, t_order *order)
{
	int	print_len;

	print_len = figure_len;
	if (order->plus || order->spc || num < 0)
		print_len += 1;
	while (print_len < order->width)
		print_len++;
	return (print_len);
}

size_t	ft_abs(long long num)
{
	if (num < 0)
		return -(num + 1) + 1u;
	return (num);
}
