/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_user.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:02:43 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 17:42:34 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_update_user(char ***user, int fd)
{
	char	**new_user;
	char	*line;
	char	*trimmed_line;

	new_user = NULL;
	line = NULL;
	while ((line = get_next_line(fd)) != NULL)
	{
		trimmed_line = ft_strtrim(line, "\n");
		free(line);
		new_user = ft_extend_split(new_user, trimmed_line);
		free(trimmed_line);
	}
	ft_free_split(user);
	*user = new_user;
}
