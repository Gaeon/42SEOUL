/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:57:38 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 15:57:47 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_cmd_env(char **env, int new_line, int fd)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (env && env[i])
	{
		if (new_line)
			count += ft_putendl_fd(env[i], fd);
		else
			count += ft_putstr_fd(env[i], fd);
		i++;
	}
	return (count);
}
