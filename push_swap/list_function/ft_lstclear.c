/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:12:40 by gaeokim           #+#    #+#             */
/*   Updated: 2023/01/15 19:03:46 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstclear_a(t_info *info, void (*del)(void *))
{
	t_node	*cur;
	t_node	*next;

	cur = info->top_a;
	while (cur)
	{
		next = cur->next;
		ft_lstdelone(cur, del);
		cur = next;
	}
	info->top_a = NULL;
	info->bottom_a = NULL;
}
