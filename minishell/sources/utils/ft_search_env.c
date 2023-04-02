/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:02:17 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 16:03:11 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minishell.h"

char	**ft_search_env(char *target, char *val, char **env, int n)
{
	char	*strs[2];
	int		arr[2];

	if (n < 0)
		n = ft_strlen(target);
	arr[0] = -1;
	strs[0] = ft_strjoin(target, "=");
	strs[1] = ft_strjoin(strs[0], val);
	free(strs[0]);
	while (env && env[++arr[0]] && !ft_strchr(target, '='))
	{
		arr[1] = n;
		if (arr[1] < ft_strchr_r(env[arr[0]], '='))
			arr[1] = ft_strchr_r(env[arr[0]], '=');
		if (!ft_strncmp(env[arr[0]], target, arr[1]))
		{
			strs[0] = env[arr[0]];
			env[arr[0]] = strs[1];
			free(strs[0]);
			return (env);
		}
	}
	env = ft_extend_split(env, strs[1]);
	free(strs[1]);
	return (env);
}
