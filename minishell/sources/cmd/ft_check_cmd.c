/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:57:25 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 15:58:16 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

DIR	*ft_check_cmd(t_data *data, t_list *cmd, char ***str, char *path)
{
	t_cmd	*cmd_c;
	DIR		*dir;

	dir = NULL;
	cmd_c = cmd->content;
	if (cmd_c && cmd_c->f_cmd)
		dir = opendir(*cmd_c->f_cmd);
	if (cmd_c && cmd_c->f_cmd && ft_strchr(*cmd_c->f_cmd, '/') && !dir)
	{
		*str = ft_split(*cmd_c->f_cmd, '/');
		cmd_c->f_path = ft_strdup(*cmd_c->f_cmd);
		free(cmd_c->f_cmd[0]);
		cmd_c->f_cmd[0] = ft_strdup(str[0][ft_n_rows(*str) - 1]);
	}
	else if (!ft_built(cmd_c) && cmd_c && cmd_c->f_cmd && !dir)
	{
		path = ft_get_envalue("PATH", data->env, 4);
		*str = ft_split(path, ':');
		free(path);
		cmd_c->f_path = ft_find_cmd(*str, *cmd_c->f_cmd, cmd_c->f_path);
		if (!cmd_c->f_path || !cmd_c->f_cmd[0] || !cmd_c->f_cmd[0][0])
			ft_perror(NCMD, *cmd_c->f_cmd, 127);
	}
	return (dir);
}
