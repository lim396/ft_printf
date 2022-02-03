/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 00:13:12 by shongou           #+#    #+#             */
/*   Updated: 2021/12/09 13:03:32 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*uc1;
	const unsigned char	*uc2;

	uc1 = (const unsigned char *)s1;
	uc2 = (const unsigned char *)s2;
	while (n-- > 0)
	{
		if (*uc1 != *uc2)
			return (*uc1 - *uc2);
		uc1++;
		uc2++;
	}
	return (0);
}
/*#include <string.h>
int main(void)
{
	char *s1 = NULL;
	char *s2 = NULL;
	size_t n = 1;
	memcmp(s1, s2, n);
}*/
