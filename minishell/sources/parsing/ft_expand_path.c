/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:59:03 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 16:00:02 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_expand_path(char *in_cmd, int i, int q[2], char *var)
{
	char	*str;
	char	*path;

	q[0] = 0;
	q[1] = 0;
	while (in_cmd && in_cmd[++i])
	{
		q[0] = (q[0] + (!q[1] && in_cmd[i] == '\'')) % 2;
		q[1] = (q[1] + (!q[0] && in_cmd[i] == '\"')) % 2;
		if (!q[0] && !q[1] && in_cmd[i] == '~' && (!i || in_cmd[i - 1] != '$'))
		{
			str = ft_substr(in_cmd, 0, i);
			path = ft_strjoin(str, var);
			free(str);
			str = ft_substr(in_cmd, i + 1, ft_strlen(in_cmd));
			free(in_cmd);
			in_cmd = ft_strjoin(path, str);
			free(path);
			free(str);
			return (ft_expand_path(in_cmd, i + ft_strlen(var) - 1, q, var));
		}
	}
	free(var);
	return (in_cmd);
}
