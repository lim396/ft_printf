/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 00:14:34 by shongou           #+#    #+#             */
/*   Updated: 2021/12/09 13:06:14 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	uc;
	unsigned char	*p;

	uc = (unsigned char)c;
	p = (unsigned char *)b;
	while (len-- > 0)
		*p++ = uc;
	return (b);
}
/*#include <stdio.h>
#include <string.h>
int main(void)
{
	char b1[];
	char b2[];
	char c = '0';
	size_t len = 0;
	int i = 0;
	ft_memset(b1, c, len);
	while (i < len)
		printf("%c", b1[i++]);
	printf("\n");
	i = 0;
	memset(b2, c, len);
	while (i < len)
		printf("%c", b2[i++]);
}*/
