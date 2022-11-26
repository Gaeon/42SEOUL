/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:37:06 by gaeokim           #+#    #+#             */
/*   Updated: 2022/11/26 21:20:05 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int signo)
{
	static int	num;
	static int	cnt;
	int			idx;
	int			digit;

	idx = 0;
	digit = 1;
	while (idx < cnt)
	{
		digit *= 2;
		idx++;
	}
	if (signo == SIGUSR1)
		num += digit;
	cnt++;
	if (cnt == 8)
	{
		ft_printf("%c", num);
		cnt = 0;
		num = 0;
	}
}

int	main(void)
{
	ft_printf("server pid : %d\n", getpid());
	signal(SIGUSR1, (void *)sig_handler);
	signal(SIGUSR2, (void *)sig_handler);
	while (1)
		usleep(1);
	return (0);
}
