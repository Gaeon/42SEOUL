/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johyyoon <johyyoon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:57:38 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 17:07:12 by johyyoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_cmd_env(char **env, int new_line, int fd)
{
	int	cnt;

	cnt = 0;
	while (env && *env)
	{
		if (new_line)
			cnt += ft_putendl_fd(*env++, fd);
		else
			cnt += ft_putstr_fd(*env++, fd);
	}
	return (cnt);
}
