/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:21:19 by marvin            #+#    #+#             */
/*   Updated: 2023/03/06 11:44:47 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_three_element_a(t_info *info)
{
	int	top;
	int	mid;
	int	bot;

	top = info->a->arr[0];
	mid = info->a->arr[1];
	bot = info->a->arr[2];
	if (top < mid && mid > bot && top < bot)
	{
		sa(info);
		ra(info);
	}
	if (top > mid && mid < bot && top < bot)
		sa(info);
	if (top < mid && mid > bot && top > bot)
		rra(info);
	if (top > mid && mid < bot && top > bot)
		ra(info);
	if (top > mid && mid > bot && top > bot)
	{
		sa(info);
		rra(info);
	}
}

void	ft_sort_five_element_a(t_info *info, int size)
{
	int	idx;
	int	*dup_arr;

	idx = 0;
	dup_arr = duplicate_stack(info, 1, size);
	sort_duplicate_stack(dup_arr, size);
	while (idx < size)
	{
		if (info->a->arr[0] <= dup_arr[size - 4])
			pb(info);
		else
			ra(info);
		idx++;
	}
	ft_sort_three_element_a(info);
	if (size == 5)
	{
		if (info->b->arr[0] < info->b->arr[1])
			sb(info);
		pa(info);
	}
	pa(info);
	free(dup_arr);
}

void	ft_sort_a(t_info *info, int size)
{
	if (size == 2 || size == 3)
	{
		if (info->a->arr[0] > info->a->arr[1])
			sa(info);
		if (size == 3)
		{
			if (info->a->arr[0] > info->a->arr[1])
			{
				ra(info);
				sa(info);
				rra(info);
				if (info->a->arr[0] > info->a->arr[1])
					sa(info);
			}
		}
	}
}

void	ft_sort_b(t_info *info, int size)
{
	if (size == 1)
		pa(info);
	else if (size >= 2)
	{
		if (info->b->arr[0] < info->b->arr[1])
			sb(info);
		pa(info);
		pa(info);
	}
	else if (size >= 3)
	{
		pa(info);
		ft_sort_a(info, 3);
	}
}
