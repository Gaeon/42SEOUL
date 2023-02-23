/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:34:34 by gaeokim           #+#    #+#             */
/*   Updated: 2023/02/23 18:38:19 by gaeon            ###   ########.fr       */
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
	ra(info);
	rb(info);
	write(1, "rr\n", 3);
}
