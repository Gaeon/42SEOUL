/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:39:12 by marvin            #+#    #+#             */
/*   Updated: 2023/02/23 16:25:47 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void 	duplicate_check(t_info *info, int num)
{
	int	idx;

	idx = 0;
	while (idx < info->a->size)
	{
		if (info->a->arr[idx] == num)
			print_error(6, info);
		idx++;
	}
}

void	sort_check(t_info *info)
{
	int	i;
	
	i = 0;
	while (i < info->a->size)
	{
		if (info->a->arr[i] > info->a->arr[i + 1])
			break ;
		i++;
	}
	if (i == info->a->size)
		print_error(7, info);
}

void	set_stack(int argc, char *argv[], t_info *info)
{
	int		num;
	int		argc_idx;
	int		array_idx;
	int 	split_idx;
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
			duplicate_check(info, num);
			info->a->arr[array_idx] = num;
			info->a->size++;
			array_idx++;
			split_idx++;
		}
		ft_free(split);
		argc_idx++;
	}
	sort_check(info);
}

void	init_stack(int argc, char *argv[], t_info *info)
{
	int		argc_idx;
	int		size;

	argc_idx = 0;
	size = 0;
	while(++argc_idx < argc)
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