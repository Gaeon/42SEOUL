/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyyoon <johyyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:01:32 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 18:31:42 by johyyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_get_prompt(t_data data)
{
	char	*tmp;
	char	*tmp2;
	char	*dir;

	tmp = ft_get_user(data);
	tmp2 = ft_strjoin(tmp, "");
	free(tmp);
	dir = ft_get_dir(data);
	tmp = ft_strjoin(tmp2, dir);
	free(dir);
	free(tmp2);
	tmp2 = ft_strjoin(tmp, RED);
	free(tmp);
	tmp = ft_strjoin(tmp2, "% ");
	free(tmp2);
	tmp2 = ft_strjoin(tmp, DEFAULT);
	free(tmp);
	return (tmp2);
}
