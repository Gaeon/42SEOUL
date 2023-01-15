/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_sx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 17:47:18 by gaeokim           #+#    #+#             */
/*   Updated: 2023/01/15 18:22:24 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_info *info)
{
	int	temp;

	if (info->size_a < 2)
		return ;
	temp = info->top_a->data;
	info->top_a->data = info->top_a->next->data;
	info->top_a->next->data = temp;
	write(1, "sa\n", 3);
}

void	sb(t_info *info)
{
	int	temp;

	if (info->size_b < 2)
		return ;
	temp = info->top_b->data;
	info->top_b->data = info->top_b->next->data;
	info->top_b->next->data = temp;
	write(1, "sb\n", 3);
}

void	ss(t_info *info)
{
	sa(info);
	sb(info);
	write(1, "ss\n", 3);
}
