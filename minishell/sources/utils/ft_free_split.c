/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:01:16 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 16:02:11 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_split(char ***env_split)
{
	int	i;

	i = 0;
	while (env_split && env_split[0] && env_split[0][i])
	{
		free(env_split[0][i]);
		i++;
	}
	if (env_split)
	{
		free(env_split[0]);
		*env_split = NULL;
	}
}
