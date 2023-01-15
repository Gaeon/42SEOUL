/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:48:41 by gaeokim           #+#    #+#             */
/*   Updated: 2023/01/15 18:54:54 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*ft_lstnew(int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == 0)
		return (0);
	node->data = data;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
