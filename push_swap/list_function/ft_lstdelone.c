/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:58:37 by gaeokim           #+#    #+#             */
/*   Updated: 2023/01/15 19:05:35 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstdelone(t_node *lst)
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->data);
	free(lst);
}
