#include "ft_printf.h"

t_order	init_order(void)
{
	t_order	order;

	memset(&order, 0, sizeof(t_order)); //ft_memset
	order.precision = -1;
	return (order);
}

size_t parse(const char *fmt, size_t i, va_list args, t_order *order)
{
	if (fmt[i] && strchr("-0 +#", fmt[i])) //ft_strchr
		i = parse_flags(fmt, i, order);
	if (('1' <= fmt[i] && fmt[i] <= '9') || fmt[i] == '*')
		i = parse_width(fmt, i, args, order);
	if (fmt[i] == '.')
		i = parse_precision(fmt, i, args, order);
	if (fmt[i] && strchr("diuxXp", fmt[i]))
		order->type = fmt[i];
	return (i);
}

int conversion_print(char type, int counted, va_list args, t_order *order)
{
	if (type == 'd' || type == 'i')
		counted = print_signed(va_arg(args, int), counted, order);
	else if (type == 'u')
		counted = print_unsigned(va_arg(args, unsigned int), counted, 10, order);
	else if (type == 'x' || type == 'X')
		counted = print_unsigned(va_arg(args, unsigned int), counted, 16, order);	
	else if (type == 'c')
		counted = print_char((unsigned char)va_arg(args, int), counted, order);
	else if (type == 's')
		counted = print_str(va_arg(args, const char *), counted, order);
	else if (type == 'p')
		counted = print_unsigned((size_t)va_arg(args, void *), counted, 16, order);
	else if (type == '%')
		counted = print_char('%', counted, order);
	return (counted);
}

int ft_vsprintf(const char *fmt, va_list args)
{
	t_order order;
	size_t i;
	int counted;

	i = 0;
	counted = 0;
	while (fmt[i])
	{
		while (fmt[i] != '%' && fmt[i] != '\0')
		{
			if (counted == INT_MAX - 1)
				return (-1);
			write(1, &fmt[i++], 1);
			counted++;
		}
		if (fmt[i] == '\0')
			break ;	
		order = init_order();
		i = parse(fmt, i + 1, args, &order);
		if (order.width == INT_MAX || order.precision == INT_MAX)
			return (-1);
		counted = conversion_print(fmt[i], counted, args, &order);
		if (counted < 0)
			return (-1);
		i++;
	}
	return (counted);
}

int ft_printf(const char *fmt, ...)
{
	va_list		args;
	int			printed_count;

	va_start(args, fmt);
	printed_count = ft_vsprintf(fmt, args);
	va_end(args);
	return (printed_count);
}
