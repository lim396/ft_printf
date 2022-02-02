#include "ft_printf.h"

int	print_ordinary_char(const char *fmt, size_t i, int *count)
{
	while (fmt[i] != '%' && fmt[i] != '\0')
	{
		if (*count == INT_MAX - 1)
		{
			*count = -1;
			return (i);
		}
		write(1, &fmt[i++], 1);
		(*count)++;
	}
	return (i);
}

size_t	parse(const char *fmt, size_t i, va_list ap, t_order *order)
{
	if (fmt[i] && strchr("-0 +#", fmt[i])) //ft_strchr
		i = parse_flags(fmt, i, order);
	if (('1' <= fmt[i] && fmt[i] <= '9') || fmt[i] == '*')
		i = parse_width(fmt, i, ap, order);
	if (fmt[i] == '.')
		i = parse_precision(fmt, i, ap, order);
	if (fmt[i] && strchr("diuxXp", fmt[i]))
		order->type = fmt[i];
	return (i);
}

int	conversion_print(char type, int count, va_list ap, t_order *order)
{
	if (type == 'd' || type == 'i')
		count = print_signed(va_arg(ap, int), count, order);
	else if (type == 'u')
		count = print_unsigned(va_arg(ap, unsigned int), count, 10, order);
	else if (type == 'x' || type == 'X')
		count = print_unsigned(va_arg(ap, unsigned int), count, 16, order);
	else if (type == 'c')
		count = print_char((unsigned char)va_arg(ap, int), count, order);
	else if (type == 's')
		count = print_str(va_arg(ap, const char *), count, order);
	else if (type == 'p')
		count = print_unsigned((size_t)va_arg(ap, void *), count, 16, order);
	else if (type == '%')
		count = print_char('%', count, order);
	return (count);
}

int	ft_vsprintf(const char *fmt, va_list ap)
{
	t_order	order;
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (fmt[i])
	{
		i = print_ordinary_char(fmt, i, &count);
		if (count < 0)
			return (-1);
		if (fmt[i] == '\0')
			break ;
		order = init_order();
		i = parse(fmt, i + 1, ap, &order);
		if (order.width == INT_MAX || order.precision == INT_MAX)
			return (-1);
		count = conversion_print(fmt[i], count, ap, &order);
		if (count < 0)
			return (-1);
		i++;
	}
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int			printed_count;

	va_start(ap, fmt);
	printed_count = ft_vsprintf(fmt, ap);
	va_end(ap);
	return (printed_count);
}
