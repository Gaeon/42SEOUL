/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:35:30 by gaeokim           #+#    #+#             */
/*   Updated: 2022/10/31 16:24:08 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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
		}
		str++;
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
