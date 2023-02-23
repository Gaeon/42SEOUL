/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rrx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:05:52 by gaeokim           #+#    #+#             */
/*   Updated: 2023/02/21 15:58:19 by gaeon            ###   ########.fr       */
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
	rra(info);
	rrb(info);
	write(1, "rrr\n", 4);
}
