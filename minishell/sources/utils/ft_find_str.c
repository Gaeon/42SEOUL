/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:01:12 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 16:02:11 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_find_str(char *str)
{
	int		i;
	char	*r_str;

	i = 0;
	r_str = NULL;
	while (str[i])
	{
		if (str[i] == '=')
		{
			r_str = ft_substr(str, 0, i);
			break ;
		}
		i++;
	}
	return (r_str);
}
