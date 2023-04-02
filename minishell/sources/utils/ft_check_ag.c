/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:00:37 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 16:01:39 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	*ft_check_ag(char *in_cmd, t_data *data)
{
	char	**str;
	t_cmd	*cmd;

	if (!in_cmd)
	{
		printf("exit\n");
		return (NULL);
	}
	if (in_cmd[0])
		add_history(in_cmd);
	str = ft_split_cmd(in_cmd, " ");
	free(in_cmd);
	if (!str)
		ft_perror(QUOTE, NULL, 1);
	if (!str)
		return ("");
	data = ft_resolve_cmd(str, data);
	if (data && data->cmds)
		cmd = data->cmds->content;
	if (data && data->cmds && cmd->f_cmd && ft_lstsize(data->cmds) == 1)
		data->env = ft_search_env("_", cmd->f_cmd[ft_n_rows(cmd->f_cmd) - 1],
				data->env, 1);
	if (data && data->cmds)
		ft_lstclear(&data->cmds, ft_free_fd);
	return (data);
}
