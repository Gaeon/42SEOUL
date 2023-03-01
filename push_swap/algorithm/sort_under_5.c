/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:21:19 by marvin            #+#    #+#             */
/*   Updated: 2023/03/01 17:50:36 by gaeon            ###   ########.fr       */
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

void	ft_sort_five_element_a(t_info *info)
{
	int	idx;
	int	*array;

	idx = 0;
	array = duplicate_stack(info, 1);
	sort_duplicate_stack(array, info->a->size + 1);
	while (idx < 5)
	{
		if (array[1] >= info->a->arr[0])
			pb(info);
		else
			ra(info);
		idx++;
	}
	ft_sort_three_element_a(info);
	if (info->b->arr[0] < info->b->arr[1])
		sb(info);
	pa(info);
	pa(info);
	free(array);
}

void	ft_sort_three_element_b(t_info *info)
{
	int	top;
	int	mid;
	int	bot;

	top = info->b->arr[0];
	mid = info->b->arr[1];
	bot = info->b->arr[2];
	if (top < mid && mid < bot && top < bot)
	{
		sb(info);
		rrb(info);
	}
	if (top < mid && mid > bot && top < bot)
		rb(info);
	if (top < mid && mid > bot && top > bot)
		rrb(info);
	if (top > mid && mid < bot && top > bot)
		sb(info);
	if (top > mid && mid > bot && top > bot)
	{
		sb(info);
		rb(info);
	}
}

void	ft_sort_five_element_b(t_info *info)
{
	int	idx;
	int	*array;

	idx = 0;
	array = duplicate_stack(info, 2);
	sort_duplicate_stack(array, info->b->size + 1);
	while (idx < 5)
	{
		if (array[3] <= info->b->arr[0])
			pa(info);
		else
			rb(info);
		idx++;
	}
	ft_sort_three_element_b(info);
	if (info->a->arr[0] > info->a->arr[1])
		sb(info);
	pb(info);
	pb(info);
	free(array);
}

