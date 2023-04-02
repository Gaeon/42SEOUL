/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_user.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:01:36 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 17:45:33 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_get_user(t_data data)
{
	char	**user;
	char	*tmp;
	char	*tmp2;

	user = NULL;
	tmp2 = NULL;
	ft_search_user(&user, "/usr/bin/whoami", "whoami", data.env);
	tmp2 = ft_strjoin(NULL, GREEN);
	tmp = ft_strjoin(tmp2, *user);
	free(tmp2);
	ft_free_split(&user);
	return (tmp);
}
