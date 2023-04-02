/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extend_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:01:09 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 16:02:07 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_extend_split(char **env, char *new_str)
{
	char	**env_split;
	int		i;
	int		n_rows;

	i = -1;
	env_split = NULL;
	if (!new_str)
		return (env);
	n_rows = ft_n_rows(env);
	env_split = malloc(sizeof(char *) * (n_rows + 2));
	env_split[n_rows + 1] = NULL;
	if (!env_split)
		return (env);
	while (++i < n_rows)
	{
		env_split[i] = ft_strdup(env[i]);
		if (!env_split[i])
		{
			ft_free_split(&env);
			ft_free_split(&env_split);
		}
	}
	env_split[i] = ft_strdup(new_str);
	ft_free_split(&env);
	return (env_split);
}
