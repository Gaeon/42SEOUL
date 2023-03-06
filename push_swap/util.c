/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:08:43 by gaeokim           #+#    #+#             */
/*   Updated: 2023/03/06 10:45:38 by gaeon            ###   ########.fr       */
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
