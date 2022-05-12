/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_of_print_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:59:29 by shongou           #+#    #+#             */
/*   Updated: 2022/05/12 11:59:31 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strnlen(const char *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && str[i] != '\0')
		i++;
	return (i);
}

void	ft_putnstr(const char *s, size_t n)
{
	if (!s)
		return ;
	else
		write(1, s, n);
}
