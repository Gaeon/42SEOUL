/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:59:58 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 16:01:00 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_word_count(char *in_cmd, char *set, int count)
{
	int	q[2];
	int	i;

	i = 0;
	q[0] = 0;
	q[1] = 0;
	while (in_cmd && in_cmd[i])
	{
		count++;
		if (!ft_strchr(set, in_cmd[i]))
		{
			while ((!ft_strchr(set, in_cmd[i]) || q[0]
					|| q[1]) && in_cmd[i] != '\0')
			{
				q[0] = (q[0] + (!q[1] && in_cmd[i] == '\'')) % 2;
				q[1] = (q[1] + (!q[0] && in_cmd[i] == '\"')) % 2;
				i++;
			}
			if (q[0] || q[1])
				return (-1);
		}
		else
			i++;
	}
	return (count);
}
