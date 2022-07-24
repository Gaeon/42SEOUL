/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:12:08 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/22 12:46:19 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	char	chr;

	chr = (char)c;
	while (*s != '\0')
	{
		if (*s == chr)
			return ((char *)s);
		s++;
	}
	if (chr == '\0')
		return ((char *)s);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

static int	ft_numlen(long l_n, long sign)
{
	int	len;

	len = 0;
	if (sign == -1)
		len++;
	while (l_n > 0)
	{
		l_n /= 10;
		len++;
	}
	return (len);
}

char	*ft_fill_str(int len, long sign, long l_n)
{
	char	*nbr;

	nbr = (char *)malloc(sizeof(char) * (len + 1));
	if (nbr == 0)
		return (0);
	nbr[len] = '\0';
	len--;
	if (l_n == 0)
		sign = 1;
	while (len >= 0)
	{
		if (len == 0 && sign == -1)
		{
			nbr[len] = '-';
			return (nbr);
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
	long	sign;
	long	l_n;

	l_n = (long)n;
	if (l_n <= 0)
		sign = -1;
	else
		sign = 1;
	len = ft_numlen(l_n * sign, sign);
	return (ft_fill_str(len, sign, l_n * sign));
}