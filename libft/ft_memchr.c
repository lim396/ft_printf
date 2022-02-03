/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 00:12:51 by shongou           #+#    #+#             */
/*   Updated: 2021/11/30 03:06:50 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*us;
	unsigned char		uc;

	us = (const unsigned char *)s;
	uc = (unsigned char)c;
	while (n-- > 0)
	{
		if (*us == uc)
			return ((void *)us);
		us++;
	}
	return (NULL);
}
/*#include <string.h>
int main(void)
{
	char *s = NULL;
	int c = 48;
	size_t n = 0;
	memchr(s, c, n);
}*/
