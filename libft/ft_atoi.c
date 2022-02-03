/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 23:39:11 by shongou           #+#    #+#             */
/*   Updated: 2021/11/05 23:39:14 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	integer;
	int		sign;

	integer = 0;
	sign = 1;
	while (('\t' <= *str && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		sign = (44 - *str);
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		if (sign * integer > (LONG_MAX - (*str - '0')) / 10)
			return ((int)LONG_MAX);
		else if (sign * integer < (LONG_MIN + (*str - '0')) / 10)
			return ((int)LONG_MIN);
		integer = (integer * 10) + (*str - '0');
		str++;
	}
	return (integer * sign);
}
/*#include <string.h>
#include <stdio.h>
int main(void)
{
	const char *str = "";
	printf("ft   %d\n", ft_atoi(str));
	printf("real %d\n", atoi(str));
}*/
