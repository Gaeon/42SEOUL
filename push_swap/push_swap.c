/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:39:12 by marvin            #+#    #+#             */
/*   Updated: 2023/03/07 14:55:26 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		free(str[idx]);
		idx++;
	}
	free(str);
}

int	print_error(int type, t_info *info)
{
	if (type == 1)
		;
	if (type == 2)
		free(info->a->arr);
	if (type == 3)
	{
		write(2, "Error\n", 6);
		free(info->a->arr);
		free(info->b->arr);
	}
	exit(1);
}

int	main(int argc, char *argv[])
{
	t_info	info;
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc >= 2)
	{
		info.a = &stack_a;
		info.b = &stack_b;
		init_stack(argc, argv, &info);
		set_stack(argc, argv, &info);
		ft_sort(&info);
		free(info.a->arr);
		free(info.b->arr);
	}
	return (0);
}
