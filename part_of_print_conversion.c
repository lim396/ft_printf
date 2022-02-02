#include "ft_printf.h"

int	print_char(char c, int count, t_order *order)
{
	int	printed_len;

	printed_len = 1;
	while (printed_len < order->width)
		printed_len++;
	if (count + printed_len >= INT_MAX)
		return (-1);
	if (!(order->left))
	{
		while (--order->width > 0)
			write(1, " ", 1);
	}
	write(1, &c, 1);
	while (--order->width > 0)
		write(1, " ", 1);
	return (count + printed_len);
}

int	print_str(const char *str, int count, t_order *order)
{
	size_t	printable_len;
	size_t	printed_len;	

	if (!str)
		str = "(null)";
	printable_len = ft_strnlen(str, order->precision);
	printed_len = printable_len;
	while (printed_len < (size_t)order->width)
		printed_len++;
	if (printed_len + count >= INT_MAX)
		return (-1);
	if (!order->left)
	{
		while ((int)printable_len < order->width--)
			write(1, " ", 1);
	}
	ft_putnstr(str, printable_len);
	while ((int)printable_len < order->width--)
		write(1, " ", 1);
	return (count + (int)printed_len);
}

int	print_unsigned(size_t n, int count, int base, t_order *order)
{
	int	figure_len;
	int	print_len;

	figure_len = count_digit(n, base);
	while (figure_len < order->precision)
		figure_len++;
	print_len = unsigned_will_print_len(figure_len, order);
	if (count + print_len >= INT_MAX)
		return (-1);
	if (n == 0 && order->precision == 0)
		return (print_prefix_or_sign(count, print_len, order));
	if (order->hash || order->type == 'p')
		order->width -= 2;
	if (!order->left && !order->zero)
	{
		while (figure_len < order->width--)
			write(1, " ", 1);
	}
	if (convert_print_u(n, base, figure_len, order) == -1)
		return (-1);
	while (figure_len < order->width--)
		write(1, " ", 1);
	return (count + print_len);
}

int	print_signed(int n, int count, t_order *order)
{
	int	figure_len;
	int	print_len;

	figure_len = count_digit(ft_abs(n), 10);
	while (figure_len < order->precision)
		figure_len++;
	print_len = singed_will_print_len(figure_len, n, order);
	if (count + print_len >= INT_MAX)
		return (-1);
	if (n == 0 && order->precision == 0)
		return (print_prefix_or_sign(count, print_len, order));
	if (order->plus || order->spc || n < 0)
		order->width--;
	if (!order->left && !order->zero)
	{
		while (figure_len < order->width--)
			write(1, " ", 1);
	}
	if (convert_print_s(n, figure_len, order) == -1)
		return (-1);
	while (figure_len < order->width--)
		write(1, " ", 1);
	return (count + print_len);
}
