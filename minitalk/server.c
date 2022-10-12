/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:09:21 by gaeokim           #+#    #+#             */
/*   Updated: 2022/09/25 18:50:11 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_info	g_info;

void	init(void)
{
	ft_printf("server pid : %d\n", getpid());
	g_info.cnt = 0;
	g_info.c = 0;
}

void	ft_handler(int signum)
{
	if (signum == SIGUSR1)
		g_info.c = g_info.c * 2 + 1;
	else
		g_info.c = g_info.c * 2;
	if (g_info.cnt == 7)
	{
		ft_printf("%c", g_info.c);
		g_info.cnt = 0;
		g_info.c = 0;
	}
	g_info.cnt++;
}

int	main(void)
{
	init();
	signal(SIGINT, (void *)ft_handler);
	while (1)
		pause();
	return (0);
}
