/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ch_env_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:57:20 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 15:58:10 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_ch_env_name(char *str)
{
	int		i[2];
	char	*s_str;

	i[0] = 0;
	i[1] = 0;
	s_str = "~@#%^-+:i.,\0";
	while (str[i[0]])
	{
		i[1] = 0;
		if (str[i[0]] == '=')
			break ;
		while (s_str[i[1]])
		{
			if (str[i[0]] == s_str[i[1]])
			{
				printf("-bash: export: not valid in this context\n");
				return (1);
			}
			i[1]++;
		}
		i[0]++;
	}
	return (0);
}
