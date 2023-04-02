/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_inoutfile.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:58:14 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 15:59:03 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmd	*ft_get_infile(t_cmd *cmd, char **tmp, int *i)
{
	char	*str[2];
	char	*str2[2];
	char	*new_line;

	str2[0] = NULL;
	str2[1] = NULL;
	str[0] = NULL;
	str[1] = "bash: warning: heredocument delimited by EOF";
	new_line = "bash: syntax error near unexpected token `newline\'";
	(*i)++;
	if (tmp[++(*i)])
	{
		str[0] = tmp[*i];
		cmd->input_fd = ft_heredoc(str2, str);
	}
	if (!tmp[*i] || cmd->input_fd == -1)
	{
		*i = -1;
		if (cmd->input_fd != -1)
		{
			ft_putendl_fd(new_line, 2);
			g_status_number = 258;
		}
	}
	return (cmd);
}

t_cmd	*ft_get_infile_2(t_cmd *cmd, char **tmp, int *i)
{
	char	*new_line;
	int		f[2];

	f[0] = 0;
	f[1] = 1;
	new_line = "bash: syntax error near unexpected token `newline\'";
	(*i)++;
	if (tmp[*i])
		cmd->input_fd = ft_getfd(cmd->input_fd, tmp[*i], f);
	if (!tmp[*i] || cmd->input_fd == -1)
	{
		*i = -1;
		if (cmd->input_fd != -1)
		{
			ft_putendl_fd(new_line, 2);
			g_status_number = 258;
		}
		else
			g_status_number = 1;
	}
	return (cmd);
}

t_cmd	*ft_get_outfile(t_cmd *cmd, char **tmp, int *i)
{
	char	*new_line;
	int		f[2];

	f[0] = 1;
	f[1] = 1;
	new_line = "bash: syntax error near unexpected token `newline\'";
	(*i)++;
	if (tmp[++(*i)])
		cmd->output_fd = ft_getfd(cmd->output_fd, tmp[*i], f);
	if (!tmp[*i] || cmd->output_fd == -1)
	{
		*i = -1;
		if (cmd->output_fd != -1)
		{
			ft_putendl_fd(new_line, 2);
			g_status_number = 258;
		}
		else
			g_status_number = 1;
	}
	return (cmd);
}

t_cmd	*ft_get_outfile_2(t_cmd *cmd, char **tmp, int *i)
{
	char	*new_line;
	int		f[2];

	f[0] = 1;
	f[1] = 0;
	new_line = "bash: syntax error near unexpected token `newline\'";
	(*i)++;
	if (tmp[*i])
		cmd->output_fd = ft_getfd(cmd->output_fd, tmp[*i], f);
	if (!tmp[*i] || cmd->output_fd == -1)
	{
		*i = -1;
		if (cmd->output_fd != -1)
		{
			ft_putendl_fd(new_line, 2);
			g_status_number = 258;
		}
		else
			g_status_number = 1;
	}
	return (cmd);
}
