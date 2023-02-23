/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_px.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:46:02 by gaeokim           #+#    #+#             */
/*   Updated: 2023/02/23 18:38:22 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_front(t_stack *stack)
{
	int	idx;

	idx = 0; 
	while (idx < stack->size)
	{
		stack->arr[idx] = stack->arr[idx + 1];
		idx++;
	}
	stack->size--;
}

void	push_back(t_stack *stack)
{
	int	idx;

	stack->size++;
	idx = stack->size;
	while (idx > 0)
	{
		stack->arr[idx] = stack->arr[idx - 1];
		idx--;
	}
}

void	pa(t_info *info)
{
	int	temp;

	if (info->b->size > -1)
	{
		temp = info->b->arr[0];
		push_back(info->a);
		info->a->arr[0] = temp;
		push_front(info->b);
		write(1, "pa\n", 3);
	}
}


void	pb(t_info *info)
{
	int	temp;

	if (info->a->size > -1)
	{
		temp = info->a->arr[0];
		push_back(info->b);
		info->b->arr[0] = temp;
		push_front(info->a);
		write(1, "pb\n", 3);
	}
}
