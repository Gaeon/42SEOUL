/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ch_env_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:57:20 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 17:35:42 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_ch_env_name(char *str)
{
	char	*invalid_chars;
	size_t	len;
	char	*p;
	int		i;

	i = -1;
	len = ft_strlen(str);
	invalid_chars = "~@#%^-+:.,";
	while (++i < (int)len)
	{
		if (str[i] == '=')
			return (0);
		p = ft_strchr(invalid_chars, str[i]);
		if (p != NULL)
		{
			printf("-bash: export: not valid in this context\n");
			return (1);
		}
	}
	return (0);
}
