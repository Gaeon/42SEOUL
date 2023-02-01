/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:53:26 by gaeokim           #+#    #+#             */
/*   Updated: 2023/02/01 18:59:40 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	array_size(int argc, char *argv[])
{
	int		idx;
	int		size;
	char	**split;

	idx = 0;
	size = 0;
	while (idx < argc)
	{
		split = ft_split(argv[i], ' ');
		size += ft_split_size(split);
		ft_free(split);
		i++;
	}
	return (size);
}

int	*ft_set_array(int argc, char *argv[], int arr_size)
{
	int 	idx_argc;
	int		idx_arr;
	int		idx_split;
	int		*array;
	char	**split;

	idx_argc = 1;
	idx_arr = 0;
	array = (int *)malloc(sizeof(int) * (arr_size - 1));
	if (!array)
		ft_error(1);
	while (idx_argc < argc)
	{
		split = ft_split(argv[idx_argc], ' ');
		idx_split = 0;
		while (split[idx_split])
		{
			array[idx_arr] = ft_atoi(split[idx_split]);
			idx_split++;
		}
	}
}