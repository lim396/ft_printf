/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 00:05:48 by shongou           #+#    #+#             */
/*   Updated: 2021/11/06 00:05:56 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}
/*#include <ctype.h>
#include <stdio.h>
int main(void)
{
	char c = '\0';
	printf("ft   %d\n" ,ft_isalpha(c));
	printf("real %d\n" ,isalpha(c));
}*/
