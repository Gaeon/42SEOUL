/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:34:34 by gaeokim           #+#    #+#             */
/*   Updated: 2023/03/01 17:24:46 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_info *info)
{
	int	idx;
	int	temp;

	idx = 0;
	temp = info->a->arr[0];
	while (idx < info->a->size)
	{
		info->a->arr[idx] = info->a->arr[idx + 1];
		idx++;
	}
	info->a->arr[idx] = temp;
	write(1, "ra\n", 3);
}

void	rb(t_info *info)
{
	int	idx;
	int	temp;

	idx = 0;
	temp = info->b->arr[0];
	while (idx < info->b->size)
	{
		info->b->arr[idx] = info->b->arr[idx + 1];
		idx++;
	}
	info->b->arr[idx] = temp;
	write(1, "rb\n", 3);
}

void	rr(t_info *info)
{
	int	idx_a;
	int	idx_b;
	int	temp_a;
	int	temp_b;

	idx_a = 0;
	idx_b = 0;
	temp_a = info->a->arr[0];
	temp_b = info->b->arr[0];
	while (idx_a < info->a->size || idx_b < info->b->size)
	{
		if (idx_a < info->a->size)
		{
			info->a->arr[idx_a] = info->a->arr[idx_a + 1];
			idx_a++;
		}
		if (idx_b < info->b->size)
		{
			info->b->arr[idx_b] = info->b->arr[idx_b + 1];
			idx_b++;
		}
	}
	info->a->arr[idx_a] = temp_a;
	info->b->arr[idx_b] = temp_b;
	write(1, "rr\n", 3);
}
