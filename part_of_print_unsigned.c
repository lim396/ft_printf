#include "ft_printf.h"

int	convert_print_u(size_t n, size_t base, int figure_len, t_order *order)
{
	char	*numstr;
	int		write_len;

	numstr = reserve_mem(&figure_len, order);
	if (!numstr)
		return (-1);
	write_len = figure_len;
	if (order->type == 'p' || (order->hash && base == 16 && n != 0))
		print_prefix(order);
	numstr = add_precision(numstr, order);
	if (n == 0)
		numstr[--figure_len] = '0';
	while (n)
	{
		if (order->type == 'X')
			numstr[--figure_len] = "0123456789ABCDEF"[n % base];
		else
			numstr[--figure_len] = "0123456789abcdef"[n % base];
		n = n / base;
	}
	write(1, numstr, write_len);
	free(numstr);
	return (0);
}

int	unsigned_will_print_len(int figure_len, size_t n, t_order *order)
{
	int	print_len;

	print_len = figure_len;
	if ((order->hash && n != 0) || order->type == 'p')
		print_len += 2;
	while (print_len < order->width)
		print_len++;
	return (print_len);
}
