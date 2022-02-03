/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 23:41:07 by shongou           #+#    #+#             */
/*   Updated: 2021/11/05 23:42:24 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')
		|| ('0' <= c && c <= '9'));
}
/*#include <ctype.h>
#include <stdio.h>
int main(void)
{
	char c = '\0';
	printf("ft   %d\n" ,ft_isalnum(c));
	printf("real %d\n" ,isalnum(c));
}*/
