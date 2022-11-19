/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:37:06 by gaeokim           #+#    #+#             */
/*   Updated: 2022/11/19 09:40:42 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_idx[2];

void	sig_handler(int signo)
{
	int	n;
	int	m;

	n = 0;
	m = 1;
	while (n < g_idx[1])
	{
		m *= 2;
		n++;
	}
	if (signo == SIGUSR1)
		g_idx[0] += m;
	else if (signo == SIGUSR2)
		;
	g_idx[1]++;
	if (g_idx[1] == 8)
	{
		ft_printf("%c", g_idx[0]);
		g_idx[1] = 0;
		g_idx[0] = 0;
	}
}

int	main(void)
{
	ft_printf("server pid : %d\n", getpid());
	if (signal(SIGUSR1, (void *)sig_handler)
		|| signal(SIGUSR2, (void *)sig_handler))
		;
	while (1)
		usleep(1);
	return (0);
}
