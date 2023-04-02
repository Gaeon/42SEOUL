/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:58:24 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 15:59:18 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_heredoc(char *str2[2], char *str[2])
{
	int	fd[2];

	g_status_number = 0;
	if (pipe(fd) == -1)
	{
		ft_perror(PIPERR, NULL, 1);
		return (-1);
	}
	str2[1] = ft_heredoc_2(str2, 0, str[0], str[1]);
	write(fd[WRITE_END], str2[1], ft_strlen(str2[1]));
	free(str2[1]);
	close(fd[WRITE_END]);
	if (g_status_number == 1)
	{
		close(fd[READ_END]);
		return (-1);
	}
	return (fd[READ_END]);
}

char	*ft_heredoc_2(char *str2[2], size_t len, char *limit, char *warn)
{
	char	*tmp;

	(void)warn;
	while (g_status_number != 1 && (!str2[0]
			|| ft_strncmp(str2[0], limit, len)
			|| ft_strlen(limit) != len))
	{
		tmp = str2[1];
		str2[1] = ft_strjoin(str2[1], str2[0]);
		free(tmp);
		free(str2[0]);
		str2[0] = readline("> ");
		if (!str2[0])
			break ;
		tmp = str2[0];
		str2[0] = ft_strjoin(str2[0], "\n");
		free(tmp);
		len = ft_strlen(str2[0]) - 1;
	}
	free(str2[0]);
	return (str2[1]);
}
