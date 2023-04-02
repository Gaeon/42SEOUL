/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:59:37 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 16:00:42 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_replace(char ***in_cmd, char **in_cmd_2, int n)
{
	char	**str;
	int		q[3];

	q[0] = -1;
	q[1] = -1;
	q[2] = -1;
	if (!in_cmd || !*in_cmd || n < 0 || n >= ft_n_rows(*in_cmd))
		return (NULL);
	str = ft_calloc(ft_n_rows(*in_cmd) + ft_n_rows(in_cmd_2), sizeof(char *));
	while (str && in_cmd[0][++q[0]])
	{
		if (q[0] != n)
			str[++q[2]] = ft_strdup(in_cmd[0][q[0]]);
		else
		{
			while (in_cmd_2 && in_cmd_2[++q[1]])
				str[++q[2]] = ft_strdup(in_cmd_2[q[1]]);
		}
	}
	ft_free_split(in_cmd);
	*in_cmd = str;
	return (*in_cmd);
}
