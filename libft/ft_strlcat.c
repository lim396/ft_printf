/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 23:34:30 by shongou           #+#    #+#             */
/*   Updated: 2021/11/05 23:34:36 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	left_size;
	size_t	dstlen;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	left_size = dstsize;
	while (left_size-- > 0 && dst[i] != '\0')
		i++;
	dstlen = i;
	left_size = dstsize - dstlen;
	if (left_size == 0)
		return (dstlen + ft_strlen(src));
	while (src[j] != '\0' && left_size > 1)
	{
		dst[i++] = src[j++];
		left_size--;
	}
	dst[i] = '\0';
	return (dstlen + ft_strlen(src));
}
/*#include <string.h>
#include <stdio.h>
int main(void)
{
	char *dst1 = NULL;
	char *dst2 = NULL;
	const char *src = NULL;
	size_t destsize = 0;
	size_t len;

	printf("ft   dst:%s src:%s size:%zu\n", dst1, src, destsize);
	len = ft_strlcat(dst1, src, destsize);
	printf("dst:%s ret:%zu\n\n", dst1, len);
	
	printf("real dst:%s src:%s size:%zu\n", dst2, src, destsize);
	len = strlcat(dst2, src, destsize);
	printf("dst:%s ret:%zu\n", dst2, len);
}*/
