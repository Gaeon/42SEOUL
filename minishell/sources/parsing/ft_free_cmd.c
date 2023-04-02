/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:59:11 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 16:00:09 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list	*ft_free_cmd(t_list *cmds, char **in_cmd, char **tmp)
{
	ft_lstclear(&cmds, ft_free_fd);
	ft_free_split(&in_cmd);
	ft_free_split(&tmp);
	return (NULL);
}
