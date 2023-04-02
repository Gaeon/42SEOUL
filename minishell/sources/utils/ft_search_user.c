/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_user.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:02:23 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 16:06:21 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_search_user(char ***user, char *full, char *ag, char **env)
{
	pid_t	pid;
	int		fd[2];
	char	**str;

	pipe(fd);
	pid = fork();
	if (!pid)
	{
		close(fd[READ_END]);
		str = ft_split(ag, ' ');
		dup2(fd[WRITE_END], STDOUT_FILENO);
		close(fd[WRITE_END]);
		if (!access(full, F_OK))
			execve(full, str, env);
		exit(1);
	}
	close(fd[WRITE_END]);
	waitpid(pid, NULL, 0);
	ft_update_user(user, fd[READ_END]);
	close(fd[READ_END]);
}
