/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_user.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyyoon <johyyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:02:43 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 18:31:33 by johyyoon         ###   ########.fr       */
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
	while (1)
	{
		line = get_next_line(fd);
		if (line != NULL)
		{
			trimmed_line = ft_strtrim(line, "\n");
			free(line);
			new_user = ft_extend_split(new_user, trimmed_line);
			free(trimmed_line);
		}
	}
	ft_free_split(user);
	*user = new_user;
}
