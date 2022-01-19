#include "ft_printf.h"

int print_char(char c, int counted, t_order *order)
{
	int printed_len;

	printed_len = 1;
	if (printed_len < order->width)
		printed_len++;
	if (counted + printed_len >= INT_MAX)
		return (-1);
	if (!(order->left))
	{
		while (--order->width > 0)
			write(1, " ", 1);
	}
	write(1, &c, 1);
	while (--order->width > 0)
		write(1, " ", 1);
	return (counted + printed_len);
}

int print_str(const char *str, int counted, t_order *order)
{
	size_t	printable_len;
	size_t	printed_len;	

	if (!str)
		str = "(null)"; // const  rewrite?
	printable_len = ft_strnlen(str, order->precision);
	printed_len = printable_len;
	while (printed_len < (size_t)order->width)
		printed_len++;
	if (printed_len + counted >= INT_MAX)
		return (-1);
	if (!order->left)
	{
		while ((int)printable_len < order->width--)
			write(1, " ", 1);
	}
	ft_putnstr(str, printable_len);
	while ((int)printable_len < order->width--)
		write(1, " ", 1);
	return (counted + (int)printed_len);
}

int print_unsigned(size_t num, int counted, int base, t_order *order)
{
	int figure_len;
	int print_len;

	figure_len = count_digit(num, base);
	while (figure_len < order->precision)
		figure_len++;
	print_len = unsigned_will_print_len(figure_len, order);
	if (counted + print_len >= INT_MAX)
		return (-1);
	if (num == 0 && order->precision == 0)
		return (print_prefix_or_sign(counted, print_len, order));
	if (order->hash || order->type == 'p')
		order->width -= 2;
	if (!order->left && !order->zero)
	{
		while (figure_len < order->width--)
			write(1, " ", 1);	
	}
	if (print_u_conversion(num, base, figure_len, order) == -1)
		return (-1);
	while (figure_len < order->width--)
		write(1, " ", 1);
	return (counted + print_len);
}

int	print_signed(int num, int counted, t_order *order)
{
	int figure_len;
	int print_len;

	figure_len = count_digit(ft_abs(num), 10);
	while (figure_len < order->precision)
		figure_len++;
	print_len = singed_will_print_len(figure_len, num, order);
	if (counted + print_len >= INT_MAX)
		return (-1);
	if (num == 0 && order->precision == 0)
		return (print_prefix_or_sign(counted, print_len, order));
	if (order->plus || order->spc || num < 0)
		order->width--;
	if (!order->left && !order->zero)
	{
		while (figure_len < order->width--)
			write(1, " ", 1);
	}
	if (print_s_conversion(num, figure_len, order) == -1)
		return (-1);
	while (figure_len < order->width--)
		write(1, " ", 1);
	return (counted + print_len);
}
