/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 01:34:07 by shongou           #+#    #+#             */
/*   Updated: 2021/11/06 01:34:09 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	uc1;
	unsigned char	uc2;

	while (n--)
	{
		uc1 = (unsigned char) *(s1++);
		uc2 = (unsigned char) *(s2++);
		if (uc1 != uc2)
			return (uc1 - uc2);
		if (uc1 == '\0')
			return (0);
	}
	return (0);
}
/*#include <string.h>
#include <stdio.h>
int main(void)
{
	const char *s1 = "";
	const char *s2 = "";
	size_t n = 0;
	printf("ft   %d\n", ft_strncmp(s1, s2, n));
	printf("real %d\n", strncmp(s1, s2, n));
}*/
