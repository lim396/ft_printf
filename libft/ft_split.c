/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 00:21:46 by shongou           #+#    #+#             */
/*   Updated: 2021/12/09 19:12:01 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_split(char const *s, char c)
{
	size_t		i;

	i = 0;
	while (*s)
	{
		if (*s++ != c && (*s == c || !*s))
			i += 1;
	}
	return (i);
}

static void	*all_free(char **arr, size_t i)
{
	while (i--)
		free(arr[i]);
	free(arr);
	return (NULL);
}

static char	**reserve_arr(size_t count)
{
	char	**arr;

	arr = (char **)malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return (NULL);
	arr[count] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	size_t		count;
	size_t		i;
	char		**split_arr;
	char const	*head;

	i = 0;
	if (!s)
		return (NULL);
	count = count_split(s, c);
	split_arr = reserve_arr(count);
	if (!split_arr)
		return (NULL);
	while (i < count)
	{
		while (*s == c)
			s++;
		head = s;
		while (*s && (*s != c))
			s++;
		split_arr[i++] = ft_substr(head, 0, s - head);
		if (!split_arr[i - 1])
			return (all_free(split_arr, i - 1));
	}
	return (split_arr);
}
