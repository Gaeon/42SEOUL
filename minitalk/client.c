/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:21:42 by gaeokim           #+#    #+#             */
/*   Updated: 2022/11/19 09:53:28 by gaeokim          ###   ########.fr       */
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
			{
				kill(pid, SIGUSR1);
				usleep(100);
			}
			else
			{
				kill(pid, SIGUSR2);
				usleep(100);
			}
			idx++;
		}
		str++;
		usleep(100);
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		client(pid, argv[2]);
	}
	return (0);
}
