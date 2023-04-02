/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 15:58:50 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 17:57:49 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_cmd_split(char *in_cmd, char *set)
{
	char	**str;
	int		w_c;
	int		q[3];

	q[0] = 0;
	q[1] = 0;
	q[2] = 0;
	if (!in_cmd)
		return (NULL);
	w_c = ft_word_count(in_cmd, set, 0);
	if (w_c == -1)
		return (NULL);
	str = malloc(sizeof(char *) * (w_c + 1));
	if (!str)
		return (NULL);
	str = ft_fill_cmd(str, in_cmd, set, q);
	str[w_c] = NULL;
	return (str);
}
