/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_px.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:46:02 by gaeokim           #+#    #+#             */
/*   Updated: 2023/01/15 18:46:43 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_info *info)
{
	t_node	*temp;

	if (info->size_b == 0)
		return ;
	temp = info->top_b;
	if (info->size_b > 1)
	{
		info->top_b = info->top_b->next;
		info->top_b->prev = NULL;
	}
	if (info->size_a == 0)
	{
		temp->next = NULL;
		info->top_a = temp;
		info->bottom_a = temp;
	}
	else
	{
		temp->next = info->top_a;
		info->top_a->prev = temp;
		info->top_a = temp;
	}
	info->size_a++;
	info->size_b--;
	write(1, "pa\n", 3);
}

void	pb(t_info *info)
{
	t_node	*temp;

	if (info->size_a == 0)
		return ;
	temp = info->top_a;
	if (info->size_a > 1)
	{
		info->top_a = info->top_a->next;
		info->top_a->prev = NULL;
	}
	if (info->size_b == 0)
	{
		temp->next = NULL;
		info->top_b = temp;
		info->bottom_b = temp;
	}
	else
	{
		temp->next = info->top_b;
		info->top_b->prev = temp;
		info->top_b = temp;
	}
	info->size_b++;
	info->size_a--;
	write(1, "pb\n", 3);
}
