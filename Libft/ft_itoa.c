/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 14:17:43 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/17 15:12:30 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(long l_n)
{
	int	len;

	len = 0;
	if (l_n <= 0)
	{
		l_n *= -1;
		len++;
	}
	while (l_n > 0)
	{
		l_n /= 10;
		len++;
	}
	return (len);
}

char	*ft_fill_str(int len, int sign, long l_n)
{
	char	*nbr;

	nbr = (char *)malloc(sizeof(char) * (len + 1));
	if (nbr == 0)
		return (0);
	nbr[len] = '\0';
	len--;
	if (l_n < 0)
		l_n *= -1;
	while (len >= 0)
	{
		if (len == 0 && sign == -1)
		{
			nbr[len] = '-';
			len--;
		}
		nbr[len] = l_n % 10 + '0';
		l_n /= 10;
		len--;
	}
	return (nbr);
}

char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	long	l_n;

	l_n = (long)n;
	len = ft_numlen(l_n);
	if (l_n < 0)
		sign = -1;
	else
		sign = 1;
	return (ft_fill_str(len, sign, l_n));
}
