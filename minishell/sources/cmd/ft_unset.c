/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:58:35 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 17:33:13 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_unset(t_data *data)
{
	char	**ag;
	char	*str;
	int		q[3];

	q[0] = 0;
	q[2] = 2;
	ag = ((t_cmd *)data->cmds->content)->f_cmd;
	if (ft_n_rows(ag) >= 2)
	{
		while (ag[++q[0]])
		{
			if (ag[q[0]][ft_strlen(ag[q[0]]) - 1] != '=')
			{
				str = ft_strjoin(ag[q[0]], "=");
				free(ag[q[0]]);
				ag[q[0]] = str;
			}
			if (ft_env_var(ag[q[0]], data->env, q) != -1)
				ft_replace(&data->env, NULL, q[1]);
			else
				return (1);
		}
	}
	return (0);
}
