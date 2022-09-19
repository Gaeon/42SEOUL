/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:35:30 by gaeokim           #+#    #+#             */
/*   Updated: 2022/09/19 14:38:00 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#include <stdio.h>
int	main(int argc, char *argv[])
{
	if (argc > 3)
		return (0);
	printf("%d %d", SIGUSR1, SIGUSR2);
}
