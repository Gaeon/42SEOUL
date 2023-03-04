/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:39:12 by marvin            #+#    #+#             */
/*   Updated: 2023/03/04 12:59:39 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

//Error 부분 Subject 요구사항에 맞게 고치기!!!
#include <stdio.h>

void	result(t_info *info)
{
	int	i;

	i = 0;
	ft_printf("\na	b\n---------\n");
	while (i <= info->a->size || i <= info->b->size)
	{
		if (i <= info->a->size)
			ft_printf("%d	", info->a->arr[i]);
		else
			ft_printf("-	");
		if (i <= info->b->size)
			ft_printf("%d\n", info->b->arr[i]);
		else
			ft_printf("-\n");
		i++;
	}
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
		result(&info);
		free(info.a->arr);
		free(info.b->arr);
	}
	return (0);
}
