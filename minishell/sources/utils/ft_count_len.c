/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:00:46 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 16:01:49 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_count_len(char *s1)
{
	int	sq;
	int	dq;
	int	count;
	int	i;

	i = 0;
	sq = 0;
	dq = 0;
	count = 0;
	while (s1 && s1[i])
	{
		sq = (sq + (!dq && s1[i] == '\'')) % 2;
		dq = (dq + (!sq && s1[i] == '\"')) % 2;
		if ((s1[i] == '\"' && !sq) || (s1[i] == '\'' && !dq))
			count++;
		i++;
	}
	if (sq || dq)
		return (-1);
	return (count);
}
