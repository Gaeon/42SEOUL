/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:39:12 by marvin            #+#    #+#             */
/*   Updated: 2023/03/01 17:26:27 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf/ft_printf.h"

//Error 부분 Subject 요구사항에 맞게 고치기!!!
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_info	info;
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc < 2)
		print_error(1, &info);
	info.a = &stack_a;
	info.b = &stack_b;
	init_stack(argc, argv, &info);
	set_stack(argc, argv, &info);
	
	
	ft_sort(&info);
	
	int i = 0;
	ft_printf("\na	b\n---------\n");
	while (i <= info.a->size || i <= info.b->size)
	{
		if (i <= info.a->size)
			ft_printf("%d	", info.a->arr[i]);
		else
			ft_printf("-	");
		if (i <= info.b->size)
			ft_printf("%d\n", info.b->arr[i]);
		else
			ft_printf("-\n");
		i++;
	}
	return (0);
}
