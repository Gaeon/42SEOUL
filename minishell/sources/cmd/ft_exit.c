/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:57:57 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 15:58:31 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_exit(t_list *cmd, int *exit_n)
{
	t_cmd		*tmp;
	long long	status[2];

	tmp = cmd->content;
	*exit_n = !cmd->next;
	if (*exit_n)
		ft_putstr_fd("exit\n", 2);
	if (!tmp->f_cmd || !tmp->f_cmd[1])
		return (0);
	status[1] = ft_atol(tmp->f_cmd[1], &status[0]);
	if (status[1] == -1)
	{
		ft_putstr_fd("bash: exit: ", 2);
		ft_putstr_fd(tmp->f_cmd[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		return (255);
	}
	else if (tmp->f_cmd[2])
	{
		*exit_n = 0;
		ft_putstr_fd("bash: exit: too manyarguments\n", 2);
		return (1);
	}
	status[0] %= 256 + 256 * (status[0] < 0);
	return (status[0]);
}
