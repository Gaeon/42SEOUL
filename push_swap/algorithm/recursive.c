/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 12:54:16 by gaeokim           #+#    #+#             */
/*   Updated: 2023/03/06 10:55:54 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_pivot(t_info *info, int size, int flag)
{
	int	*arr;
	int	pivot;

	arr = duplicate_stack(info, flag, size);
	sort_duplicate_stack(arr, size);
	pivot = size / 4;
	if (flag == 1)
	{
		info->pivot1 = arr[size - pivot];
		info->pivot2 = arr[size - pivot * 2];
	}
	else
	{
		info->pivot1 = arr[pivot * 2 - 1];
		info->pivot2 = arr[pivot - 1];
	}
	free(arr);
}

void	push_to_a_step(t_info *info, t_argument *arg_cnt, int size)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		if (info->b->arr[0] <= info->pivot2)
		{
			rb(info);
			arg_cnt->rb++;
		}
		else
		{
			pa(info);
			arg_cnt->pa++;
			if (info->a->arr[0] <= info->pivot1)
			{
				ra(info);
				arg_cnt->ra++;
			}
		}
		idx++;
	}
}

void	push_to_a(t_info *info, int size)
{
	int			idx;
	t_argument	arg_cnt;

	arg_cnt = (t_argument){0, 0, 0, 0};
	if (is_stack_sorted(info, 2, size))
	{
		while (size--)
			pa(info);
		return ;
	}
	if (size <= 3)
	{
		ft_sort_b(info, size);
		return ;
	}
	get_pivot(info, size, 2);
	push_to_a_step(info, &arg_cnt, size);
	push_to_b(info, arg_cnt.pa - arg_cnt.ra);
	idx = -1;
	while (++idx < arg_cnt.ra)
		rrr(info);
	push_to_b(info, arg_cnt.rb);
	push_to_a(info, arg_cnt.ra);
}

void	push_to_b_step(t_info *info, t_argument *arg_cnt, int size)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		if (info->a->arr[0] >= info->pivot1)
		{
			ra(info);
			arg_cnt->ra++;
		}
		else
		{
			pb(info);
			arg_cnt->pb++;
			if (info->b->arr[0] >= info->pivot2)
			{
				rb(info);
				arg_cnt->rb++;
			}
		}
		idx++;
	}
}

void	push_to_b(t_info *info, int size)
{
	int			idx;
	t_argument	arg_cnt;

	arg_cnt = (t_argument){0, 0, 0, 0};
	if (is_stack_sorted(info, 1, size))
		return ;
	if (size <= 3)
	{
		ft_sort_a(info, size);
		return ;
	}
	get_pivot(info, size, 1);
	push_to_b_step(info, &arg_cnt, size);
	idx = -1;
	while (++idx < arg_cnt.ra)
		rrr(info);
	push_to_b(info, arg_cnt.ra);
	push_to_a(info, arg_cnt.rb);
	push_to_a(info, arg_cnt.pb - arg_cnt.rb);
}
