/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getpid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:01:41 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 16:02:34 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_getpid(t_data *data)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
	{
		ft_perror(FORKERR, NULL, 1);
		ft_free_split(&data->env);
		exit(1);
	}
	if (!pid)
	{
		ft_free_split(&data->env);
		exit(1);
	}
	waitpid(pid, NULL, 0);
	data->pid = pid;
}
