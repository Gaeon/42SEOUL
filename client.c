/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:21:42 by gaeokim           #+#    #+#             */
/*   Updated: 2022/11/19 02:06:54 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int		idx;
	int		sign;
	long	ret;

	idx = 0;
	sign = 1;
	ret = 0;
	while ((9 <= str[idx] && str[idx] <= 13) || str[idx] == 32)
		idx++;
	if (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			sign = -1;
		idx++;
	}
	while ('0' <= str[idx] && str[idx] <= '9')
	{
		ret = ret * 10 + str[idx] - '0';
		if (sign == 1 && ret > 2147483647)
			return (-1);
		else if (sign == -1 && ret > 2147483648)
			return (0);
		idx++;
	}
	return ((int)sign * ret);
}

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
				usleep(10);
			}
			else
			{
				kill(pid, SIGUSR2);
				usleep(10);
			}
			idx++;
		}
		str++;
		usleep(10);
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

// int	main(int argc, char *argv[])
// {
// 	pid_t	pid;

// 	if (argc == 2)
// 	{
// 		pid = atoi(argv[1]);
// 		kill(pid, SIGUSR1);
// 		kill(pid, SIGUSR2);
// 	}
// 	return (0);
// }
