/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 13:03:21 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 16:13:16 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	main(int ac, char **ag, char **envp)
{
	char	*str;
	char	*out;
	t_data	data;

	(void)ac;
	data = ft_init_data(ag, envp);
	while (1)
	{
		signal(SIGINT, ft_sig_c);
		signal(SIGQUIT, SIG_IGN);
		str = ft_get_prompt(data);
		if (str)
			out = readline(str);
		else
			out = readline("minishell $ ");
		free(str);
		if (!ft_check_ag(out, &data))
			break ;
	}
	exit(g_status_number);
}
