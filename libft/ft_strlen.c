/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 01:20:19 by shongou           #+#    #+#             */
/*   Updated: 2021/11/06 01:20:21 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
/*#include <string.h>
#include <stdio.h>
int main(void)
{
	const char *str = "";
	printf("ft   %zu\n", ft_strlen(str));
	printf("real %zu\n", strlen(str));
}*/
