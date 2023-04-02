/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:59:07 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 16:00:08 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_fill_cmd(char **str, const char *in_cmd, char *set, int q[3])
{
	int	q_2[2];

	q_2[0] = 0;
	q_2[1] = 0;
	while (in_cmd && in_cmd[q[0]])
	{
		q[1] = q[0];
		if (!ft_strchr(set, in_cmd[q[0]]))
		{
			while ((!ft_strchr(set, in_cmd[q[0]])
					|| q_2[0] || q_2[1]) && in_cmd[q[0]])
			{
				q_2[0] = (q_2[0] + (!q_2[1] && in_cmd[q[0]] == '\'')) % 2;
				q_2[1] = (q_2[1] + (!q_2[0] && in_cmd[q[0]] == '\"')) % 2;
				q[0]++;
			}
		}
		else
			q[0]++;
		str[q[2]++] = ft_substr(in_cmd, q[1], q[0] - q[1]);
	}
	return (str);
}

char	**ft_fill_cmd_2(char **str, const char *in_cmd, char *c, int q[3])
{
	int	len;
	int	q_2[2];

	q_2[0] = 0;
	q_2[1] = 0;
	len = ft_strlen(in_cmd);
	while (in_cmd[q[0]])
	{
		while (ft_strchr(c, in_cmd[q[0]]) && in_cmd[q[0]])
			q[0]++;
		q[1] = q[0];
		while ((!ft_strchr(c, in_cmd[q[0]])
				|| q_2[0] || q_2[1]) && in_cmd[q[0]])
		{
			q_2[0] = (q_2[0] + (!q_2[1] && in_cmd[q[0]] == '\'')) % 2;
			q_2[1] = (q_2[1] + (!q_2[0] && in_cmd[q[0]] == '\"')) % 2;
			q[0]++;
		}
		if (q[1] >= len)
			str[q[2]++] = "\0";
		else
			str[q[2]++] = ft_substr(in_cmd, q[1], q[0] - q[1]);
	}
	return (str);
}
