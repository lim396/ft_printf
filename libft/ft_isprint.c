/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 00:07:31 by shongou           #+#    #+#             */
/*   Updated: 2021/11/06 00:07:36 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (32 <= c && c <= 126);
}
/*#include <ctype.h>
#include <stdio.h>
int main(void)
{
	char c = '\0';
	printf("ft   %d\n" ,ft_isprint(c));
	printf("real %d\n" ,isprint(c));
}*/
