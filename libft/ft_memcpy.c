/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 00:13:58 by shongou           #+#    #+#             */
/*   Updated: 2021/11/30 03:07:06 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	if (d == s || n == 0)
		return (dst);
	while (n--)
		*d++ = *s++;
	return (dst);
}
/*#include <string.h>
int main(void)
{
	char *dst = NULL;
	char *src = NULL;
	size_t n = 1000;
	memcpy(dst, src, n);
}*/
