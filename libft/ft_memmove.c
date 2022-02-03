/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 00:14:18 by shongou           #+#    #+#             */
/*   Updated: 2021/12/09 19:42:00 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d == s || n == 0)
		return (dest);
	if (d < s)
	{
		while (n--)
			*(d++) = *(s++);
	}
	else
	{
		d += n - 1;
		s += n - 1;
		while (n--)
			*(d--) = *(s--);
	}
	return (dest);
}
/*#include <string.h>
int main(void)
{
	char *dest = NULL;
	char *src = NULL;
	size_t n = 1;
	ft_memmove(dest, src, n);
}*/
