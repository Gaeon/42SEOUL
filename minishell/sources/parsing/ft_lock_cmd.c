/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lock_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:59:24 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 16:00:27 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list	*ft_lock_cmd(char **in_cmd, int i)
{
	t_list	*cmds[2];
	char	**tmp[2];

	cmds[0] = NULL;
	tmp[1] = ft_lock_trim_cmd(in_cmd);
	while (in_cmd[++i])
	{
		cmds[1] = ft_lstlast(cmds[0]);
		if (!i || (in_cmd[i][0] == '|' && in_cmd[i + 1] && in_cmd[i + 1][0]))
		{
			i += in_cmd[i][0] == '|';
			ft_lstadd_back(&cmds[0], ft_lstnew(ft_create_cmd()));
			cmds[1] = ft_lstlast(cmds[0]);
		}
		tmp[0] = in_cmd;
		cmds[1]->content = ft_redirec_pipe(cmds[1]->content, tmp, &i);
		if (i < 0)
			return (ft_free_cmd(cmds[0], in_cmd, tmp[1]));
		if (!in_cmd[i])
			break ;
	}
	ft_free_split(&tmp[1]);
	ft_free_split(&in_cmd);
	return (cmds[0]);
}	
