/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 01:34:51 by shongou           #+#    #+#             */
/*   Updated: 2021/11/06 01:34:55 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_pos_c;
	char	find_c;

	last_pos_c = NULL;
	find_c = (char)c;
	while (1)
	{
		if (*s == find_c)
			last_pos_c = (char *)s;
		if (!*s)
			break ;
		s++;
	}
	return (last_pos_c);
}
