/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 00:08:08 by shongou           #+#    #+#             */
/*   Updated: 2021/11/30 03:04:17 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(int n)
{
	int				count;
	unsigned int	num;

	count = 1;
	if (n < 0)
	{
		count++;
		num = -(n + 1) + 1u;
	}
	else
		num = n;
	while (num > 9)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int				figure_len;
	char			*numstr;
	unsigned int	num;

	figure_len = count_digit(n);
	numstr = (char *)malloc(sizeof(char) * (figure_len + 1));
	if (!numstr)
		return (NULL);
	numstr[figure_len] = '\0';
	if (n == 0)
		numstr[0] = '0';
	if (n < 0)
	{
		numstr[0] = '-';
		num = -(n + 1) + 1u;
	}
	else
		num = n;
	while (num)
	{
		numstr[--figure_len] = (num % 10) + '0';
		num = num / 10;
	}
	return (numstr);
}
