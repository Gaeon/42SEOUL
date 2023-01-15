/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rrx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:05:52 by gaeokim           #+#    #+#             */
/*   Updated: 2023/01/15 18:12:30 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_info *info)
{
	t_node	*temp;

	if (info->size_a < 2)
		return ;
	temp = info->bottom_a;
	info->bottom_a = temp->prev;
	info->bottom_a->next = NULL;
	info->top_a->prev = temp;
	temp->next = info->top_a;
	info->top_a = temp;
	info->top_a->prev = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_info *info)
{
	t_node	*temp;

	if (info->size_b < 2)
		return ;
	temp = info->bottom_b;
	info->bottom_b = temp->prev;
	info->bottom_b->next = NULL;
	info->top_b->prev = temp;
	temp->next = info->top_b;
	info->top_b = temp;
	info->top_b->prev = NULL;
	write(1, "rrb\n", 4);
}

void	rrr(t_info *info)
{
	rra(info);
	rrb(info);
	write(1, "rrr\n", 4);
}
