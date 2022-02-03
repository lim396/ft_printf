/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 00:09:38 by shongou           #+#    #+#             */
/*   Updated: 2021/12/08 02:47:01 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_ptr;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		next_ptr = (*lst)->next;
		ft_lstdelone(*lst, (*del));
		*lst = next_ptr;
	}
}
