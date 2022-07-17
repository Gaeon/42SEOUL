/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:17:14 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/17 17:44:33 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*cur;

	head = cur;
	if (lst == 0 || f == 0 || del == 0)
		return (0);
	while (lst)
	{
		cur->content = f(lst->content);
		cur->next = lst->next;
		cur = cur->next;
		lst = lst->next;
	}
	return (head);
}
