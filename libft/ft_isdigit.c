/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 00:07:09 by shongou           #+#    #+#             */
/*   Updated: 2021/11/06 00:07:16 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}
/*#include <ctype.h>
#include <stdio.h>
int main(void)
{
	char c = '\0';
	printf("ft   %d\n" ,ft_isdigit(c));
	printf("real %d\n" ,isdigit(c));
}*/
