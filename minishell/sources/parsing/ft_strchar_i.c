/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchar_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:59:53 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 18:02:10 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_strchar_i(char *in_cmd, char *set)
{
	int	i;

	i = 0;
	if (!in_cmd)
		return (-1);
	while (in_cmd[i])
	{
		if (ft_strchr(set, in_cmd[i]))
			return (i);
		i++;
	}
	return (-1);
}
