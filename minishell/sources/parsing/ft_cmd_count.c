/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:58:44 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 17:55:36 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_cmd_count(const char *in_cmd, char *set, int c[2])
{
	int	arr[2];

	arr[0] = 0;
	arr[1] = 0;
	while (in_cmd[c[0]])
	{
		if (!ft_strchr(set, in_cmd[c[0]]))
		{
			c[1]++;
			while ((!ft_strchr(set, in_cmd[c[0]])
					|| arr[0]) && in_cmd[c[0]] != '\0')
			{
				if (!arr[1] && (in_cmd[c[0]] == '\"' || in_cmd[c[0]] == '\''))
					arr[1] = in_cmd[c[0]];
				arr[0] = (arr[0] + (in_cmd[c[0]] == arr[1])) % 2;
				arr[1] *= arr[0] != 0;
				c[0]++;
			}
			if (arr[0])
				return (-1);
		}
		else
			c[0]++;
	}
	return (c[1]);
}
