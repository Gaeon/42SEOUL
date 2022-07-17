/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:31:55 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/17 17:39:40 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print(int n, int fd)
{
	char	nbr[10];
	int		index;

	index = 0;
	while (n != 0)
	{
		nbr[index] = n % 10 + '0';
		n /= 10;
		index++;
	}
	index--;
	while (index >= 0)
	{
		write(fd, &nbr[index], 1);
		index--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(fd, "-2147483648", 11);
			return ;
		}
		else
		{
			write(fd, "-", 1);
			n *= -1;
		}
	}
	ft_print(n, fd);
}
