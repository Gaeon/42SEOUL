/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 22023/03/10 16:00:09 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 16:00:17 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_get_cmd(t_data *data, t_list *cmd, char **str, char *path)
{
	t_cmd	*cmd_c;
	DIR		*dir;

	cmd_c = cmd->content;
	dir = ft_check_cmd(data, cmd, &str, path);
	if (cmd_c && cmd_c->f_cmd && !ft_built(cmd_c) && dir)
		ft_perror(ISDIR, *cmd_c->f_cmd, 126);
	else if (cmd_c && cmd_c->f_path && !ft_built(cmd_c)
		&& access(cmd_c->f_path, F_OK) == -1)
		ft_perror(NDIR, cmd_c->f_path, 127);
	else if (cmd_c && cmd_c->f_path && !ft_built(cmd_c)
		&& access(cmd_c->f_path, X_OK) == -1)
		ft_perror(NPERM, cmd_c->f_path, 126);
	if (dir)
		closedir(dir);
	ft_free_split(&str);
}

void	*ft_run_cmd(t_data *data, t_list *cmd)
{
	int	fd[2];

	ft_get_cmd(data, cmd, NULL, NULL);
	if (pipe(fd) == -1)
		return (ft_perror(PIPERR, NULL, 1));
	if (!ft_check_fork(data, cmd, fd))
		return (NULL);
	close(fd[WRITE_END]);
	if (cmd->next && !((t_cmd *)cmd->next->content)->input_fd)
		((t_cmd *)cmd->next->content)->input_fd = fd[READ_END];
	else
		close(fd[READ_END]);
	if (((t_cmd *)cmd->content)->input_fd > 2)
		close(((t_cmd *)cmd->content)->input_fd);
	if (((t_cmd *)cmd->content)->output_fd > 2)
		close(((t_cmd *)cmd->content)->output_fd);
	return (NULL);
}
