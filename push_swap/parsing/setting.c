/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:39:12 by marvin            #+#    #+#             */
/*   Updated: 2023/02/26 17:54:38 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sort_duplicate_input(t_info *info, int *arr)
{
	int	i;
	int	j;
	int	temp;
	int	sorted;

	i = -1;
	sorted = 0;
	while (++i < info->size)
	{
		j = -1;
		while (++j < info->size - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				sorted++;
			}
		}
		if (arr[i] == arr[i + 1])
			print_error(8, info);
	}
	return (sorted);
}

int	duplicate_input(t_info *info, int *arr)
{
	int	idx;

	idx = 0;
	while (idx < info->size)
	{
		arr[idx] = info->a->arr[idx];
		idx++;
	}
}

void	input_check(t_info *info)
{
	int	*arr;
	int	sorted;

	arr = (int *)malloc(sizeof(int) * info->size);
	if (arr == 0)
		print_error(8, info);
	duplicate_input(info, arr);
	sorted = sort_duplicate_input(info, arr);
	if (sorted == 0)
		print_error(8, info);
	info->arr = arr;
}

void	set_stack(int argc, char *argv[], t_info *info)
{
	int		num;
	int		argc_idx;
	int		array_idx;
	int		split_idx;
	char	**split;

	argc_idx = 1;
	array_idx = 0;
	while (argc_idx < argc)
	{
		split = ft_split(argv[argc_idx], ' ');
		split_idx = 0;
		while (split[split_idx] != 0)
		{
			num = ft_atoi_check(split[split_idx], info);
			info->a->arr[array_idx] = num;
			info->a->size++;
			array_idx++;
			split_idx++;
		}
		ft_free(split);
		argc_idx++;
	}
	input_check(info);
}

void	init_stack(int argc, char *argv[], t_info *info)
{
	int		argc_idx;
	int		size;

	argc_idx = 0;
	size = 0;
	while (++argc_idx < argc)
		size += ft_word_cnt(argv[argc_idx], ' ');
	info->a->arr = (int *)malloc(sizeof(int) * size);
	if (info->a->arr == 0)
		print_error(2, info);
	info->b->arr = (int *)malloc(sizeof(int) * size);
	if (info->b->arr == 0)
		print_error(3, info);
	info->size = size;
	info->a->size = -1;
	info->b->size = -1;
}
