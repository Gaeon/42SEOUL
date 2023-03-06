/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:38:07 by gaeokim           #+#    #+#             */
/*   Updated: 2023/03/06 11:14:24 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_stack_sorted(t_info *info, int flag, int size)
{
	int	idx;

	idx = 0;
	while (flag == 1 && idx < size - 1)
	{
		if (info->a->arr[idx] > info->a->arr[idx + 1])
			return (0);
		idx++;
	}
	while (flag == 2 && idx < size - 1)
	{
		if (info->b->arr[idx] < info->b->arr[idx + 1])
			return (0);
		idx++;
	}
	return (1);
}

void	sort_duplicate_stack(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	*duplicate_stack(t_info *info, int flag, int size)
{
	int	idx;
	int	*array;

	idx = 0;
	array = (int *)malloc(sizeof(int) * (size));
	if (!array)
		exit(1);
	while (flag == 1 && idx < size)
	{
		array[idx] = info->a->arr[idx];
		idx++;
	}
	while (flag == 2 && idx < size)
	{
		array[idx] = info->b->arr[idx];
		idx++;
	}
	return (array);
}
