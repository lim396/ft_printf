/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 01:42:51 by shongou           #+#    #+#             */
/*   Updated: 2021/12/14 10:36:46 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		c -= ('a' - 'A');
	return (c);
}
/*#include <stdio.h>
#include <ctype.h>
int main(void)
{
	char c = '';
	printf("ft   %c\n", ft_toupper(c));
	printf("real %c\n", toupper(c));
}*/
