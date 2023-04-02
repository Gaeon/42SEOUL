/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:57:43 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 15:58:00 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_cmd_export(t_data *data)
{
	char	**str[2];
	int		i;

	i = 0;
	str[0] = ((t_cmd *)data->cmds->content)->f_cmd;
	while (data->env[i])
		printf("declare -x %s\n", data->env[i++]);
	return (0);
}
