/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:21:19 by marvin            #+#    #+#             */
/*   Updated: 2023/03/06 20:42:15 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	element_under_5(t_info *info, int flag, int size)
{
	if (flag == 1)
	{
		if (size == 2)
			sa(info);
		else if (size == 3)
			ft_sort_three_element_a(info);
		else if (size == 4 || size == 5)
			ft_sort_five_element_a(info, size);
	}
	else
		ft_sort_b(info, size);
}

void	ft_sort(t_info *info)
{
	if (!is_stack_sorted(info, 1, info->size))
	{
		if (info->a->size < 5)
			element_under_5(info, 1, info->a->size + 1);
		else
			push_to_b(info, info->a->size + 1);
	}
}
