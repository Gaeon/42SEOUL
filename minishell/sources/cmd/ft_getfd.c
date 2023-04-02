/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getfd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:58:20 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 17:53:58 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_getfd(int o_fd, char *path, int f[2])
{
	int	fd;

	if (o_fd > 2)
		close(o_fd);
	if (!path)
		return (-1);
	if (access(path, F_OK) == -1 && !f[0])
		ft_perror(NDIR, path, 127);
	else if (access(path, R_OK) == -1 && !f[0])
		ft_perror(NPERM, path, 126);
	else if (access(path, W_OK) == -1 && !access(path, F_OK) && f[0])
		ft_perror(NPERM, path, 126);
	if (f[0] && f[1])
		fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0666);
	else if (f[0] && !f[1])
		fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	else if (!f[0] && o_fd != -1)
		fd = open(path, O_RDONLY);
	else
		fd = o_fd;
	return (fd);
}
