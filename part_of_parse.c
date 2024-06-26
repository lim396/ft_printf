/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_of_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:58:56 by shongou           #+#    #+#             */
/*   Updated: 2022/05/12 11:58:58 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_order	init_order(void)
{
	t_order	order;

	ft_memset(&order, 0, sizeof(t_order));
	order.precision = -1;
	return (order);
}

int	parse_flags(const char *fmt, size_t i, t_order *order)
{
	while (fmt[i] && ft_strchr("-0+ #", fmt[i]))
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

int	parse_width(const char *fmt, size_t i, va_list args, t_order *order)
{
	while (ft_isdigit(fmt[i]))
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
	while (ft_isdigit(fmt[i]))
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
