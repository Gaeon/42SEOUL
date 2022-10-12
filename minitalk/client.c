/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:35:30 by gaeokim           #+#    #+#             */
/*   Updated: 2022/09/25 18:48:49 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	client(pid_t pid, char *str)
{
	int	idx;

	while (*str)
	{
		idx = 0;
		while (idx < 8)
		{
			if ((*str >> idx & 1) == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			idx++;
			// usleep(10);
		}
		str++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc == 2)
	{
		pid = ft_atoi(argv[1]);
		client(pid, argv[2]);
	}
	return (0);
}
