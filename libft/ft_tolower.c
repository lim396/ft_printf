/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 01:42:28 by shongou           #+#    #+#             */
/*   Updated: 2021/12/14 10:36:12 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		c += ('a' - 'A');
	return (c);
}
/*#include <stdio.h>
#include <ctype.h>
int main(void)
{
	char c = '';
	printf("ft   %c\n", ft_tolower(c));
	printf("real %c\n", tolower(c));
}*/
