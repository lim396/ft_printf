/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 01:34:26 by shongou           #+#    #+#             */
/*   Updated: 2021/11/06 01:34:28 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needlen;
	size_t	i;

	needlen = ft_strlen(needle);
	if (*needle == '\0' || (!haystack && len == 0))
		return ((char *)haystack);
	while (*haystack && len >= needlen)
	{
		i = 0;
		while (haystack[i] == needle[i])
		{
			i++;
			if (needle[i] == '\0')
				return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (NULL);
}
