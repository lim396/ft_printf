/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 01:27:52 by shongou           #+#    #+#             */
/*   Updated: 2021/12/09 19:41:07 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	front_trim_len(char const *s, char const *set)
{
	size_t	count_front;

	count_front = 0;
	while (ft_strchr(set, *s) && *s)
	{
		s++;
		count_front++;
	}
	return (count_front);
}

static size_t	back_trim_len(char const *s, char const *set, char const *head)
{
	size_t	count_back;

	count_back = 0;
	while (s >= head && ft_strchr(set, *s))
	{
		count_back++;
		if (s == head)
			break ;
		s--;
	}
	return (count_back);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		front_len;
	size_t		back_len;
	size_t		left_strlen;
	char		*left_str;
	char const	*head;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	head = s1;
	front_len = front_trim_len(s1, set);
	while (*s1)
		s1++;
	s1--;
	back_len = back_trim_len(s1, set, head);
	if (ft_strlen(head) == front_len)
		return ((char *)ft_calloc(1, sizeof(char)));
	else
		left_strlen = ft_strlen(head) - (front_len + back_len);
	left_str = (char *)malloc(sizeof(char) * (left_strlen + 1));
	if (!left_str)
		return (NULL);
	ft_strlcpy(left_str, (head + front_len), left_strlen + 1);
	return (left_str);
}
