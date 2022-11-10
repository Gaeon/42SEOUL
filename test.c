/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:37:06 by gaeokim           #+#    #+#             */
/*   Updated: 2022/11/10 18:23:36 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<signal.h>
#include<unistd.h>

//int g_cnt = 0;
//int g_num = 0;

// void	sig_handler(int signo)
// {
// 	if (g_cnt < 8)
// 	{
// 		if (signo == SIGUSR1)
// 			g_num = g_num * 2 + 1;
// 		else if (signo == SIGUSR2)
// 			g_num = g_num * 2;
// 		g_cnt++;
// 	}
// 	else
// 	{
// 		printf("%c", g_num);
// 		g_cnt = 0;
// 		g_num = 0;
// 	}
// }

void	sig_handler(int signo)
{
	if (signo == SIGUSR1)
		printf("signal 1");
	else if (signo == SIGUSR2)
		printf("signal 2");
}

int	main(void)
{
	printf("server pid : %d\n", getpid());
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	// if (signal(SIGUSR1, sig_handler))
	// 	;
	// if (signal(SIGUSR2, sig_handler))
	// 	;
	while (1)
		sleep(1);
	return (0);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	c;

// 	c = 'a';
// 	for (int i = 7 ; i >= 0 ; --i)
// 	{
// 		printf("%d", c >> i & 1);
// 	}
// 	printf("\n");
// 	for (int j = 7 ; j >= 0 ; --j)
// 	{
// 		printf("%d ", c >> j);
// 	}
// }

// 01100001

// 00000000 0 
// 00000001 1 
// 00000011 3 
// 00000110 6 
// 00001100 12
// 00011000 24
// 00110000 48
// 01100001 97
// 1 2 4 8 16 32 64