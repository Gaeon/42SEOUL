/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:39:12 by marvin            #+#    #+#             */
/*   Updated: 2023/02/01 18:54:14 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int errno)
{
	if (errno > 1)
		write(1, "Error\n", 7);
	exit(1);
}

int	ft_parsing(char *argv, t_node *node, t_info *info)
{
	int	*arr;
	int	idx;

	idx = 0;
	arr = ft_split(argv);
	while (arr[idx])
	{
		node = ft_lstnew(arr[idx]);
		ft_lstadd_back_a(node, info);
		idx++;
	}
}

// int	main(int argc, char **argv)
// {	
// 	int		cnt;
// 	t_node	node;
// 	t_info	info;

// 	cnt = 1;
// 	if (argc < 3)
// 		exit(1);
// 	while (++cnt < argc)
// 	{
// 		if (ft_parsing(argv[cnt], &node, &info) == -1)
// 			ft_error();
// 	}
// }

int	main(int argc, char *argv[])
{
	int		arr;
	int		arr_size;
	t_node	*node;

	if (argc < 2)
		ft_error(1);
	arr_size = ft_array_size(argc, argv);
	array = ft_array(argc, argv, arr_size);
}