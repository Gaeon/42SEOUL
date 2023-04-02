/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:01:03 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 16:01:58 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_env_var(char *ag, char **env, int q[3])
{
	int	i;

	q[1] = 0;
	i = ft_strchr_r(ag, '=');
	if (ag[0] == '=' && q[2] != 3)
		return (-2);
	if (ft_isdigit(ag[0]) && q[2])
	{
		if (q[2] == 1)
			ft_putstr_fd("export: not an identifier\n", 2);
		else if (q[2] < 1)
			ft_putstr_fd("unset: invalid parameter name\n", 2);
		return (-1);
	}
	while (env[q[1]])
	{
		if (!ft_strncmp(env[q[1]], ag, i + 1))
			return (1);
		q[1]++;
	}
	return (0);
}
