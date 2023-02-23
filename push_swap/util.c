/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:08:43 by gaeokim           #+#    #+#             */
/*   Updated: 2023/02/23 16:08:15 by gaeon            ###   ########.fr       */
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
	if (type == 0) 
		return (0);
	if (type == 1)
		write(2, "Error! Argument Error\n", 23);
	if (type == 2)
		write(2, "Error! Malloc Error\n", 21);
	if (type == 3)
	{
		write(2, "Error! Malloc Error\n", 21);
		free(info->a->arr);
	}
	if (type >= 4)
	{
		if (type == 4)
			write(2, "Error! Arguments are bigger than an integer\n", 45);
		if (type == 5)
			write(2, "Error! Non numeric input\n", 26);
		if (type == 6)
			write(2, "Error! Duplicate input\n", 24);
		if (type == 7)
			write(2, "Error! Already Sorted\n", 23);
		free(info->a->arr);
		free(info->b->arr);
	}
	exit(1);
}
