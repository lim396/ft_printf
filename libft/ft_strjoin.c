/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 23:36:48 by shongou           #+#    #+#             */
/*   Updated: 2021/11/05 23:38:07 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*r_arr;
	size_t	i;
	size_t	j;

	if (!(s1 && s2))
		return (NULL);
	i = 0;
	j = 0;
	r_arr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!r_arr)
		return (NULL);
	while (s1[i])
	{
		r_arr[i] = s1[i];
		i++;
	}
	while (s2[j])
		r_arr[i++] = s2[j++];
	r_arr[i] = '\0';
	return (r_arr);
}
