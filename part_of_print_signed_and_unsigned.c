#include "ft_printf.h"

int count_digit(size_t num, size_t base)
{
	int count;

	count = 1;
	while (num > base - 1)
	{
		num = num / base;
		count++;
	}
	return (count);
}

int print_preci_and_arg_zero(int counted, int print_len, t_order *order)
{
	if (order->type == 'p' || order->plus || order->spc)
	{
		if (order->type == 'p')
			order->width -= 2;
		else
			order->width -= 1;
		if (!order->left)
		{
			while (order->width-- > 0)
				write(1, " ", 1);
		}
		if (order->type == 'p')
			write(1, "0x", 2);
		else if (order->plus)
			write(1, "+", 1);
		else
			write(1, " ", 1);
	}
	while (order->width-- > 0)
		write(1, " ", 1);
	return (counted + print_len);
}