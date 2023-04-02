/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:01:46 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 16:02:41 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_data	ft_init_data(char **ag, char **envp)
{
	t_data	data;
	char	*str;

	data.cmds = NULL;
	data.env = ft_env_split(envp);
	str = NULL;
	g_status_number = 0;
	ft_getpid(&data);
	data = ft_init(data, str, ag);
	return (data);
}
