/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:58:08 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 15:58:57 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_find_cmd(char **str, char *cmd, char *f_path)
{
	char	*tmp;
	int		i;

	i = -1;
	f_path = NULL;
	while (str && str[++i])
	{
		free(f_path);
		tmp = ft_strjoin(str[i], "/");
		if (!tmp)
			return (NULL);
		f_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!f_path)
			return (NULL);
		if (!access(f_path, F_OK))
			break ;
	}
	if (!str || !str[i])
	{
		free(f_path);
		return (NULL);
	}
	return (f_path);
}
