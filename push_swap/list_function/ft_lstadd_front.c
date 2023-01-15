/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:51:28 by gaeokim           #+#    #+#             */
/*   Updated: 2023/01/15 19:02:43 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_front_a(t_info *info, t_node *new)
{
	if (info->top_a == 0 || new == 0)
		return ;
	new->next = info->top_a;
	info->top_a = new;
}

void	ft_lstadd_front_b(t_info *info, t_node *new)
{
	if (info->top_b == 0 || new == 0)
		return ;
	new->next = info->top_b;
	info->top_b = new;
}
