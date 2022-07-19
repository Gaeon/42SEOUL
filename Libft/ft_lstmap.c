/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:17:14 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/19 18:51:40 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cur;
	t_list	*ret;

	ret = NULL;
	if (lst == 0 || f == 0 || del == 0)
		return (0);
	while (lst)
	{
		cur = ft_lstnew(f(lst->content));
		if (cur == 0)
		{
			ft_lstclear(&cur, del);
			return (0);
		}
		ft_lstadd_back(&ret, cur);
		cur = cur->next;
		lst = lst->next;
	}
	return (ret);
}
