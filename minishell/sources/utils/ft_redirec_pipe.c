/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirec_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:02:13 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 16:06:17 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd	*ft_redirec_pipe(t_cmd *cmd, char **tmp[2], int *i)
{
	if (tmp[0][*i])
	{
		if (tmp[0][*i][0] == '>' && tmp[0][*i + 1] && tmp[0][*i + 1][0] == '>')
			cmd = ft_get_outfile(cmd, tmp[1], i);
		else if (tmp[0][*i][0] == '>')
			cmd = ft_get_outfile_2(cmd, tmp[1], i);
		else if (tmp[0][*i][0] == '<' && tmp[0][*i + 1]
				&& tmp[0][*i + 1][0] == '<')
			cmd = ft_get_infile(cmd, tmp[1], i);
		else if (tmp[0][*i][0] == '<')
			cmd = ft_get_infile_2(cmd, tmp[1], i);
		else if (tmp[0][*i][0] != '|')
			cmd->f_cmd = ft_extend_split(cmd->f_cmd, tmp[1][*i]);
		else
		{
			ft_perror(PIPERR, NULL, 2);
			*i = -2;
		}
		return (cmd);
	}
	ft_perror(PIPERR, NULL, 2);
	*i = -2;
	return (cmd);
}
