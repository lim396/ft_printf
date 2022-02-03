/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 01:11:04 by shongou           #+#    #+#             */
/*   Updated: 2021/11/30 03:18:45 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*pos_c;
	char	find_c;

	pos_c = NULL;
	find_c = (char)c;
	while (1)
	{
		if (*s == find_c)
		{
			pos_c = (char *)s;
			break ;
		}
		else if (!*s)
			break ;
		s++;
	}
	return (pos_c);
}
