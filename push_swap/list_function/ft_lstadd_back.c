/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:55:10 by gaeokim           #+#    #+#             */
/*   Updated: 2023/01/15 19:01:21 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_back_a(t_node *new, t_info *info)
{
	t_node	*tail;

	if (info->top_a == 0 || new == 0)
		return ;
	if (info->top_a == 0)
	{
		info->top_a = new;
		return ;
	}
	tail = info->bottom_a;
	new->next = tail->next;
	tail->next = new;
}

void	ft_lstadd_back_b(t_node *new, t_info *info)
{
	t_node	*tail;

	if (info->top_b == 0 || new == 0)
		return ;
	if (info->top_b == 0)
	{
		info->top_b = new;
		return ;
	}
	tail = info->bottom_b;
	new->next = tail->next;
	tail->next = new;
}
