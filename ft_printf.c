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

int ft_strnlen(const char *str, size_t n)
{
	size_t i;

	//if (!str)
	//{
	//	if (n > 6)
	//		n = 6;
	//	return (n);
	//}
	i = 0;
	while (i < n && str[i] != '\0')
		i++;
	if (i >= INT_MAX)
		i = -1;
	return (i);
}

void ft_putnstr(const char *s, size_t n)
{
	if (n < 0)
		return ;
	//if (!s)
		//write(1 ,"(null)", n);
	else
		write(1, s, n); //ft_strnlen(s, n)
}


t_order	init_order(void)
{
	t_order	order;

	memset(&order, 0, sizeof(t_order));
	/*order.left = 0;
	order.zero = 0;
	order.hash = 0;
	order.plus = 0;
	order.spc = 0;
	//flags
	order.width = 0;*/
	order.precision = -1;
	//order.type = '\0';
	return (order);
}

int	parse_flags(const char *fmt, size_t i, t_order *order)
{
	while(fmt[i] == '-' || fmt[i] == '0' || fmt[i] == '+' || fmt[i] == ' '
		|| fmt[i] == '#') //fmt[i] && strchr("-0+ #", fmt[i])
	{
		if (fmt[i] == '-')
		{
			order->left = 1;
			order->zero = 0;
		}
		else if (fmt[i] == '0' && !order->left)
			order->zero = 1;
		if (fmt[i] == '+')
		{
			order->plus = 1;
			order->spc = 0;
		}
		else if (fmt[i] == ' ' && !order->plus)
			order->spc = 1;
		if (fmt[i] == '#')
			order->hash = 1;
		i++;
	}
	return (i);
}

int parse_width(const char *fmt, size_t i, va_list args, t_order *order)
{
	while (isdigit(fmt[i])) //ft_isdigit
	{
		if (order->width > (INT_MAX - (fmt[i] - '0')) / 10)
		{
			order->width = INT_MAX;
			break ;
		}
		order->width = (order->width * 10) + fmt[i++] - '0';
	}
	if (fmt[i] == '*')
	{
		order->width = va_arg(args, int);
		if (order->width < 0)
		{
			order->left = 1;
			order->zero = 0;
			if (order->width == INT_MIN)
				order->width += 1;
			order->width *= (-1);
		}
		i++;
	}
	return (i);
}

int	parse_precision(const char *fmt, size_t i, va_list args, t_order *order)
{
	i++;
	order->zero = 0;
	order->precision = 0;
	while (isdigit(fmt[i])) //ft_isdigit
	{
		if (order->precision > (INT_MAX - (fmt[i] - '0')) / 10)
		{
			order->precision = INT_MAX;
			break ;
		}
		order->precision = (order->precision * 10) + fmt[i++] - '0';
	}
	if (fmt[i] == '*')
	{
		order->precision = va_arg(args, int);
		if (order->precision < 0)
			order->precision = 0;
		i++;
	}
	return (i);
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

int print_char(char c, int counted, t_order *order)
{
	//int printed_count;
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
	//int printed_count;
	//char *s;
	int printable_len;
	int printed_len;	
	//s = va_arg(args, char *);
	if (!str)
		str = "(null)"; // const  rewrite?
	printable_len = ft_strnlen(str, order->precision);
	printed_len = printable_len;
	while (printed_len < order->width)
		printed_len++;
	if (printable_len < 0 || printed_len + counted >= INT_MAX)
		return (-1);
	if (!order->left)
	{
		while (printable_len < order->width--)
			write(1, " ", 1);
	}
	ft_putnstr(str, printable_len);
	//counted += printable_len;
	while (printable_len < order->width--)
		write(1, " ", 1);
	return (counted + printed_len);
}

int count_u_digit(size_t num, size_t base)
{
	int count;

	count = 1;
	//if (order.0x)
	//	count += 2;
	while (num > base - 1)
	{
		num = num / base;
		count++;
	}
	//while (count < order.precision)
	//	count++;
	return (count);
}

char	*reserve_mem(int *figure_len, t_order *order)
{
	char	*numstr;
	int		i;

	i = 0;
	while (order->zero && *figure_len < order->width) //cut func reserve_mem
		*figure_len += 1;
	//while (figure_len < order.precision)
	//	figure_len++;
	numstr = (char *)malloc(sizeof(char) * (*figure_len + 1)); //cut func reserve_mem
	if (!numstr)
		return (NULL);
	numstr[*figure_len] = '\0';
	return (numstr);
}

void	print_prefix(t_order *order)
{
	if(order->type == 'X')
		write(1, "0X", 2);
	else
		write(1, "0x", 2);
}

char	*add_precision(char *numstr, int num_len, t_order *order)
{
	int	i;

	i = 0;
	while (order->zero && num_len < order->width--) //cut func add_precision
		numstr[i++] = '0';
	while (num_len < order->precision--)
		numstr[i++] = '0';
	return (numstr);
}

void	print_u_conversion(size_t num, size_t base, int figure_len, t_order *order) //unsigned int  cast?
{
	//int figure_len;
	char *numstr;
	//int i;
	int num_len;
	int write_len;
	
	//figure_len = count_hex_digit(n, base);
	numstr = reserve_mem(&figure_len, order);
	/*while (figure_len < order.width && order.zero) //cut func reserve_mem
		figure_len++;
	while (figure_len < order.precision)
		figure_len++;
	numstr = (char *)malloc(sizeof(char) * (figure_len + 1)); //cut func reserve_mem
	if (!numstr)
		return ;
	numstr[figure_len] = '\0';*/
	
	if (!numstr)
		return ;
	write_len = figure_len;
	//i = 0;
	num_len = count_u_digit(num, base);
	if (order->type == 'p' || (order->hash && base == 16)) //cut func print_prefix
		print_prefix(order);
	/*{
		if(fmt == 'X')
			write(1, "0X", 2);
		else
			write(1, "0x", 2);
	}*/
	numstr = add_precision(numstr, num_len, order);
	/*while (order.zero && n_len < order.width--) //cut func add_precision
		numstr[i++] = '0';
	while (n_len < order.precision--)
		numstr[i++] = '0';*/
	while (num)
	{
		if (order->type == 'X')
			numstr[--figure_len] = "0123456789ABCDEF"[num % base];
		else
			numstr[--figure_len] = "0123456789abcdef"[num % base];
		num = num / base;
	}
	//if (fmt = 'X')
	//	str_toupper(numstr);
	write(1, numstr, write_len);
	free(numstr);
	//if (fmt == 'p' || (order.0x && base == 16))
	//	figure_len += 2;
	//return (figure_len);
}

int unsigned_print_preci_and_arg_zero(int counted, t_order *order) //int figure_len
{
	if (order->type == 'p')
	{
		order->width -= 2;
		if (!order->left)
		{
			while (order->width-- > 0)
			{
				write(1, " ", 1);
				counted++;
			}
		}
		write(1, "0x", 2);
		counted += 2;
	}
			
	while (order->width-- > 0)
	{
		write(1, " ", 1);
		counted++;
	}
	return (counted);
}


int	unsigned_will_print_len(int figure_len, t_order *order)
{
	int	print_len;

	print_len = figure_len;
	//if (n == 0 && order.precision == 0)
	//	print_len--;
	if (order->hash || order->type == 'p')
		print_len += 2;
	//if (order->plus || order->spc || num < 0)
	//	print_len += 1;
	while (print_len < order->width)
		print_len++;
	return (print_len);
}
	
int print_unsigned(size_t num, int counted, int base, t_order *order)
{
	//int printed_count;
	int figure_len;
	int print_len;
					//ft_u_numlen
	figure_len = count_u_digit(num, base); //cut func will_print_len
//	if (n == 0 && order.precision == 0)
//		print_len--;
	while (figure_len < order->precision)
		figure_len++;
	print_len = unsigned_will_print_len(figure_len, order);
	/*print_len = figure_len; //cut func will_print_len
	if (order->0x)
		print_len += 2;
	if (print_len < order->width)
		print_len++;*/

	if (counted + print_len >= INT_MAX)
		return (-1);

	//printed_count = order.precision;
	if (num == 0 && order->precision == 0) //cut func  print_pre_and_arg_zero
		return (unsigned_print_preci_and_arg_zero(counted, order)); //figure_len
	/*{
		if (conversion == 'p')
		{
			width -= 2;
			if (!order.left)
			{
				while (order.width--)
				{
					putchar(' ');
					printed_count++;
				}
			}
			write(1, "0x", 2);
			printed_count += 2;
		}
			
		while (order.width--)
		{
			putchar(c);
			printed_count++;
		}
		return (printed_count);
	}*/
	
	if (order->hash || order->type == 'p')
		order->width -= 2;
	//if (figure_len > order.precision || fmt == 'p')
	//		order.precision = print_len;
	if (!order->left && !order->zero)
	{
		while (figure_len < order->width--)
			write(1, " ", 1);	
	}
	//while (count_digit() < order.precision--)
	//	putchar('0');

	print_u_conversion(num, base, figure_len, order);
	while (figure_len < order->width--) //order.precision == figure_len
		write(1, " ", 1);
	return (counted + print_len);
}

/*int print_ptr(unsigned long long n, int counted, t_order *order)
{
	//int printed_count;
	int figure_len;
	int print_len;

	figure_len = count_u_digit(n, 16); //cut func will_print_len
	//if (n == 0 && order.precision == 0)
	//	print_len--;
	if (figure_len < order.precision)
		figure_len++;
	print_len = will_print_len(figure_len, order);
	//print_len = figure_len; //cut func will_print_len
	//print_len += 2;
	//if (print_len < order->width)
	//	print_len++;

	if(counted + print_len >= INT_MAX)
		return (-1);

	//printed_count = order.precision;
	//if (n == 0 && order.precision == 0) //cut func  unsigned pre_and_arg_zero
	//	return (unsigned_pre_and_arg_zero(counted, order));
	//{
	//	if (conversion == 'p')
	//	{
	//		width -= 2;
	//		if (!order.left)
	//		{
	//			while (order.width--)
	//			{
	//				putchar(' ');
	//				printed_count++;
	//			}
	//		}
	//		write(1, "0x", 2);
	//		printed_count += 2;
	//	}
	//		
	//	while (order.width--)
	//	{
	//		putchar(c);
	//		printed_count++;
	//	}
	//	return (printed_count);
	//}
	
	order.widht -= 2;
	//if (figure_len > order.precision || fmt == 'p')
	//		order.precision = print_len;
	if (!order.left)
	{
		while (figure_len < order.width--)
			putchar(' ');	
	}
	//while (count_digit() < order.precision--)
	//	putchar('0');
	//printed_count = print_conversion_to_hex();
	print_u_conversion(n, 16, figure_len, order);
	while (figure_len < order.width--) //order.precision == count_digit()
		putchar(' ');
	return (counted + print_len);
}*/

int count_dec_digit(int num)
{
	int count;
	unsigned int	n;

	count = 1;
	if (num < 0)
	{
		n = -(num + 1) + 1u;
		//num = num / 10 * (-1);
		//if (num > 0)
			//count++;
	}
	else
		n = num;
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	//while (count < order.precision)
	//	count++;
	return (count);
}

void	print_sign_or_spc(int num, t_order *order)
{
	if (num < 0)
		write(1, "-", 1);
	else if (order->plus)
		write(1, "+", 1);
	else
		write(1, " ", 1);
}

void	print_s_conversion(int num, int figure_len, t_order *order)
{
	char	*numstr;
	//int		i;
	int		num_len;
	int		write_len;
	
	//figure_len = count_dec_digit();
	/*while (figure_len < order.width && order.zero) //cut func reserve_mem
		figure_len++;
	while (figure_len < order.precision)
		figure_len++;*/
	numstr = reserve_mem(&figure_len, order);
	//numstr = (char *)malloc(sizeof(char) * (figure_len + 1));
	//if (!numstr)
	//	return ;
	//numstr[figure_len] = '\0';
	if (!numstr)
		return ;
	write_len = figure_len;
	//i = 0;
	num_len = count_dec_digit(num);
	if (num == 0)
		numstr[0] = '0';
	if (num < 0 || order->plus || order->spc) // cut func print_sign_or_spc
		print_sign_or_spc(num, order);
	/*{
		if (n < 0)
			write(1, "-", 1);
		else if (order.plus)
			write(1, "+", 1);
		else
			write(1, " ", 1);
	}*/
	numstr = add_precision(numstr, num_len, order);
	//while (order.zero && count_dec_digit(n) < order.width--) //cut func add_precision
	//	numstr[i++] = '0';
	//while (count_dec_digit(n) < order.precision--)
	//	numstr[i++] = '0';
	if (num < 0)
	{
		numstr[--figure_len] = num % 10 * (-1) + '0';
		num = num / 10 * (-1);
	}
	while (num)
	{
		numstr[--figure_len] = (num % 10) + '0';
		num = num / 10;
	}
	write(1, numstr, write_len);
	free(numstr);
	//return (figure_len);
}

int	sign_preci_and_arg_zero(int counted, t_order *order)
{
	if (order->plus || order->spc)
	{
		order->width -= 1;
		if (!order->left)
		{
			while (order->width-- > 0)
			{
				write(1, " ", 1);
				counted++;
			}
		}
		if (order->plus)
		{
			write(1, "+", 1);
			counted++;
		}
		else
		{
			write(1, " ", 1);
			counted++;
		}
	}		
	while (order->width-- > 0)
	{
		write(1, " ", 1);
		counted++;
	}
	return (counted);
}

int	singed_will_print_len(int figure_len, int num, t_order *order)
{
	int	print_len;

	print_len = figure_len;
	//if (n == 0 && order.precision == 0)
	//	print_len--;
	//if (order->hash || order->type == 'p')
	//	print_len += 2;
	if (order->plus || order->spc || num < 0)
		print_len += 1;
	while (print_len < order->width)
		print_len++;
	return (print_len);
}

int	print_signed(int num, int counted, t_order *order)
{
	//int printed_count;
	int figure_len;
	int print_len;

	figure_len = count_dec_digit(num); //cut func will_print_len
	while (figure_len < order->precision)
		figure_len++;
	print_len = singed_will_print_len(figure_len, num, order);
	/*while (figure_len < order.precision)
		figure_len++;
	print_len = figure_len; //cut func will_print_len
	if (n == 0 && order.precision == 0)
		print_len--;
	if (order->plus || order->spc || n < 0)
		print_len++;
	while (print_len < order->width)
		print_len++;*/
	
	if (counted + print_len >= INT_MAX)
		return (-1);
	
	//printed_count = order.precision;
	if (num == 0 && order->precision == 0) //cut func  sined_pre_and_arg_zero
		return (sign_preci_and_arg_zero(counted, order));
	/*{
		if (order.plus || order.spc)
		{
			width -= 1;
			if (!order.left)
			{
				while (order.width--)
					putchar(' ');
					counted++;
			}
			if (order.plus)
				write(1, "+", 1);
			else
				write(1, " ", 1);
			counted++;
		}
			
		while (order.width--)
		{
			putchar(' ');
			counted++;
		}
		return (counted);
	}*/

	if (order->plus || order->spc || num < 0)
		order->width--;
	//if (count_digit() > order.precision)
	//		order.precision = count_digit;
	if (!order->left && !order->zero)
	{
		while (figure_len < order->width--)
			write(1, " ", 1);
	}
	//while (count_digit() < order.precision--)
	//	putchar('0');
	print_s_conversion(num, figure_len, order);
	while (figure_len < order->width--)
		write(1, " ", 1);
	return (counted + print_len);
}

int conversion_print(char type, int counted, va_list args, t_order *order)
{
	//int printed_count;

	//printed_count = 0;
	if (type == 'd' || type == 'i')
		counted = print_signed(va_arg(args, int), counted, order);
	else if (type == 'u')
		counted = print_unsigned(va_arg(args, unsigned int), counted, 10, order);
	else if (type == 'x' || type == 'X')
		counted = print_unsigned(va_arg(args, unsigned int), counted, 16, order);	
	//else if (type == 'X')
	//	counted = print_unsigned(va_arg(args, unsigned int), counted, 16, order);
	else if (type == 'c')
		counted = print_char((unsigned char)va_arg(args, int), counted, order);
	else if (type == 's')
		counted = print_str(va_arg(args, const char *), counted, order);
	else if (type == 'p')
		counted = print_unsigned((size_t)va_arg(args, void *), counted, 16, order);
	else if (type == '%')
		counted = print_char('%', counted, order);
	//{
	//	putchar('%');
	//	counted += 1;
	//}
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
			if (counted == INT_MAX - 1) //cut func ??
				return (-1);
			write(1, &fmt[i++], 1);
			counted++;
			//continue ;
		}
		if (fmt[i] == '\0')
			break ;	
		order = init_order();
		//structure initialize
		i = parse(fmt, i + 1, args, &order);
		if (order.width == INT_MAX || order.precision == INT_MAX)
			return (-1);
		//printed_count += conversion_print();
		counted = conversion_print(fmt[i], counted, args, &order);
		if (counted < 0)
			break ; //return (-1);
		i++;
	}
	return (counted);
}

int ft_printf(const char *fmt, ...)
{
	//const char	*str;
	va_list		args;
	int			printed_count;

	va_start(args, fmt);
	printed_count = ft_vsprintf(fmt, args);
	va_end(args);
	return (printed_count);
}
