#include "ft_printf.h"

char	*reserve_mem(int *figure_len, t_order *order)
{
	char	*numstr;
	int		i;

	i = 0;
	while (order->zero && *figure_len < order->width)
		*figure_len += 1;
	numstr = (char *)malloc(sizeof(char) * (*figure_len + 1));
	if (!numstr)
		return (NULL);
	numstr[*figure_len] = '\0';
	return (numstr);
}

char	*add_precision(char *numstr, t_order *order)
{
	int	i;

	i = 0;
	while (order->zero && order->width-- > 0)
		numstr[i++] = '0';
	while (order->precision-- > 0)
		numstr[i++] = '0';
	return (numstr);
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

void	print_prefix(t_order *order)
{
	if (order->type == 'X')
		write(1, "0X", 2);
	else
		write(1, "0x", 2);
}
