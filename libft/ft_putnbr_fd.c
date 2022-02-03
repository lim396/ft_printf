/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 00:17:13 by shongou           #+#    #+#             */
/*   Updated: 2021/11/06 00:21:06 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_back_putstr_fd(int *str, int i, int fd)
{
	char	c;

	while (i >= 0)
	{
		c = str[i--] + '0';
		write(fd, &c, 1);
	}
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	int	str[11];
	int	i;

	i = 0;
	if (n == INT_MIN)
	{
		write(fd, "-2147483648", 11);
	}
	else if ((INT_MIN < n) && (n < 0))
	{
		write(fd, "-", 1);
		return (ft_putnbr_fd(-n, fd));
	}
	else if (INT_MAX >= n)
	{
		while (n > 9)
		{
			str[i] = n % 10;
			n = n / 10;
			i++;
		}
		str[i] = n;
		ft_back_putstr_fd(str, i, fd);
	}
	return ;
}
/*int main(void)
{
	int n = 0;
	int fd = 1;
	ft_putnbr_fd(n, fd);
}*/
