/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lock_trim_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyyoon <johyyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:59:29 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 18:29:31 by johyyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_lock_trim_cmd(char **in_cmd)
{
	char	**str;
	char	*tmp;
	int		i;

	i = -1;
	str = ft_env_split(in_cmd);
	while (str && str[++i])
	{
		tmp = ft_strtrim_mini(str[i], 0, 0);
		free(str[i]);
		str[i] = tmp;
	}
	return (str);
}
