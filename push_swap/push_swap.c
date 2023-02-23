/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:39:12 by marvin            #+#    #+#             */
/*   Updated: 2023/02/23 17:54:02 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Error 부분 Subject 요구사항에 맞게 고치기!!!
#include <stdio.h>
int	main(int argc, char *argv[])
{
	t_info	info;
	t_stack stack_a;
	t_stack stack_b;

	if (argc < 2)
		print_error(1, &info);
	info.a = &stack_a;
	info.b = &stack_b;
	init_stack(argc, argv, &info);
	set_stack(argc, argv, &info);
	ft_sort(&info);
	
	for(int i = 0 ; i <= info.a->size ; i++)
	{
		printf("%d ", info.a->arr[i]);
	}
	// printf("\n");
	// pb(&info); pb(&info); pb(&info); pb(&info);
	// printf("\nstack a\n");
	// for(int i = 0 ; i <= info.a->size ; i++)
	// {
	// 	printf("%d ", info.a->arr[i]);
	// }
	// printf("\nstack b\n");
	// for(int i = 0 ; i <= info.b->size ; i++)
	// {
	// 	printf("%d ", info.b->arr[i]);
	// }
	// pa(&info);
	// printf("\nstack a\n");
	// for(int i = 0 ; i <= info.a->size ; i++)
	// {
	// 	printf("%d ", info.a->arr[i]);
	// }

	return (0);
}
