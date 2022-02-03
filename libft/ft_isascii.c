/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 00:06:29 by shongou           #+#    #+#             */
/*   Updated: 2021/11/06 00:06:31 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}
/*#include <ctype.h>
#include <stdio.h>
int main(void)
{
	char c = '\0';
	printf("ft   %d\n" ,ft_isascii(c));
	printf("real %d\n" ,isascii(c));
}*/
