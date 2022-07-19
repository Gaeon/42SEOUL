/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:17:14 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/19 19:33:02 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*cur;

	if (lst == 0 || f == 0)
		return (0);
	head = ft_lstnew(f(lst->content));
	if (head == 0)
		return (0);
	cur = head;
	lst = lst->next;
	while (lst)
	{
		cur->next = ft_lstnew(f(lst->content));
		if (cur->next == 0)
		{
			ft_lstclear(&head, del);
			return (0);
		}
		cur = cur->next;
		lst = lst->next;
	}
	return (head);
}
