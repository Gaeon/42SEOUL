/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:21:19 by marvin            #+#    #+#             */
/*   Updated: 2023/03/02 11:59:32 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	element_under_5(t_info *info, int flag)
{
	if (flag == 1)
	{
		if (info->a->size == 2)
			ft_sort_three_element_a(info);
		if (info->a->size == 4)
			ft_sort_five_element_a(info);
	}
	else
	{
		if (info->b->size == 2)
			ft_sort_three_element_b(info);
		if (info->b->size == 4)
			ft_sort_five_element_b(info);
	}
}

void	ft_sort(t_info *info)
{
	if (!is_stack_sorted(info, 1))
	{
		if (info->a->size < 5)
			element_under_5(info, 1);
		else
			push_to_b(info, info->size);
	}
}
