/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:21:19 by marvin            #+#    #+#             */
/*   Updated: 2023/02/26 17:54:51 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_three_element(t_info *info)
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

void	ft_sort_four_element(t_info *info)
{
	int	idx;
	int	*array;

	idx = 0;
	array = duplicate_stack(info, 1);
	sort_duplicate_stack(array, info->a->size + 1);
	while (idx < 5)
	{
		if (array[0] == info->a->arr[0])
			pb(info);
		else
			ra(info);
		idx++;
	}
	ft_sort_three_element(info);
	pa(info);
	pa(info);
	free(array);
}

void	ft_sort_five_element(t_info *info)
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
	ft_sort_three_element(info);
	if (info->b->arr[0] < info->b->arr[1])
		sb(info);
	pa(info);
	pa(info);
	free(array);
}

void	element_under_5(t_info *info)
{
	if (info->a->size == 1)
		sa(info);
	else if (info->a->size == 2)
		ft_sort_three_element(info);
	else if (info->a->size == 3)
		ft_sort_four_element(info);
	else if (info->a->size == 4)
		ft_sort_five_element(info);
}

void	ft_sort(t_info *info)
{
	if (!is_stack_sorted(info, 1))
	{
		if (info->a->size < 5)
			element_under_5(info);
		else
			atob(&init, init.size);
	}
}
