/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shongou <shongou@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 00:11:03 by shongou           #+#    #+#             */
/*   Updated: 2021/11/06 00:11:05 by shongou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dst_head;
	t_list	*dst_tail;

	if (!f || !lst)
		return (NULL);
	dst_head = ft_lstnew((*f)(lst->content));
	if (!dst_head)
		return (NULL);
	dst_tail = dst_head;
	while (lst->next)
	{
		lst = lst->next;
		dst_tail->next = ft_lstnew((*f)(lst->content));
		if (!dst_tail->next)
		{
			ft_lstclear(&dst_head, del);
			return (NULL);
		}
		dst_tail = dst_tail->next;
	}
	return (dst_head);
}
