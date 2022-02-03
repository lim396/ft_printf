/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 01:20:47 by shongou           #+#    #+#             */
/*   Updated: 2021/11/30 03:20:33 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret_arr;
	size_t	size;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	size = ft_strlen(s) + 1;
	ret_arr = (char *)malloc(sizeof(char) * size);
	if (!ret_arr)
		return (NULL);
	ret_arr[size - 1] = '\0';
	while (s[i])
	{
		ret_arr[i] = (*f)((unsigned int)i, s[i]);
		i++;
	}
	return (ret_arr);
}
