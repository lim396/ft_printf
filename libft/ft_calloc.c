/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 23:40:08 by shongou           #+#    #+#             */
/*   Updated: 2021/11/30 03:05:40 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*reserve_mem;

	if (!(count && size))
	{
		count = 1;
		size = 1;
	}
	if (count && (size > SIZE_MAX / count))
		return (NULL);
	reserve_mem = (void *)malloc(count * size);
	if (!reserve_mem)
		return (NULL);
	ft_bzero(reserve_mem, count * size);
	return (reserve_mem);
}
