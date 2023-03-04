/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rrx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:05:52 by gaeokim           #+#    #+#             */
/*   Updated: 2023/03/04 12:54:03 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_info *info)
{
	int	idx;
	int	temp;

	idx = info->a->size;
	temp = info->a->arr[info->a->size];
	while (idx > 0)
	{
		info->a->arr[idx] = info->a->arr[idx - 1];
		idx--;
	}
	info->a->arr[idx] = temp;
	write(1, "rra\n", 4);
}

void	rrb(t_info *info)
{
	int	idx;
	int	temp;

	idx = info->b->size;
	temp = info->b->arr[info->b->size];
	while (idx > 0)
	{
		info->b->arr[idx] = info->b->arr[idx - 1];
		idx--;
	}
	info->b->arr[idx] = temp;
	write(1, "rrb\n", 4);
}

void	rrr(t_info *info)
{
	int	idx_a;
	int	idx_b;
	int	temp_a;
	int	temp_b;

	idx_a = info->a->size;
	idx_b = info->b->size;
	temp_a = info->a->arr[info->a->size];
	temp_b = info->b->arr[info->b->size];
	while (idx_a > 0 || idx_b > 0)
	{
		if (idx_a > 0)
		{
			info->a->arr[idx_a] = info->a->arr[idx_a - 1];
			idx_a--;
		}
		if (idx_b > 0)
		{
			info->b->arr[idx_b] = info->b->arr[idx_b - 1];
			idx_b--;
		}
	}
	info->a->arr[idx_a] = temp_a;
	info->b->arr[idx_b] = temp_b;
	write(1, "rrr\n", 4);
}
