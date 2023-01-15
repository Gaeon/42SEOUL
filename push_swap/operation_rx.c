/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:34:34 by gaeokim           #+#    #+#             */
/*   Updated: 2023/01/15 18:05:42 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_info *info)
{
	t_node	*temp;

	if (info->size_a < 2)
		return ;
	temp = info->top_a;
	info->top_a = info ->top_a->next;
	info->top_a->prev = NULL;
	info->bottom_a->next = temp;
	temp->prev = info->bottom_a;
	info->bottom_a = temp;
	info->bottom_a->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_info *info)
{
	t_node	*temp;

	if (info->size_b < 2)
		return ;
	temp = info->top_b;
	info->top_b = info ->top_b->next;
	info->top_b->prev = NULL;
	info->bottom_b->next = temp;
	temp->prev = info->bottom_b;
	info->bottom_b = temp;
	info->bottom_b->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_info *info)
{
	ra(info);
	rb(info);
	write(1, "rr\n", 3);
}
