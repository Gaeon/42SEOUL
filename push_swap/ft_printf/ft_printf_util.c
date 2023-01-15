/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:00:42 by gaeokim           #+#    #+#             */
/*   Updated: 2022/09/25 16:18:32 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int	ft_strchr(const char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

int	ft_putnbr(int nb)
{
	char	c;
	int		print_len;

	print_len = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		nb = -nb;
		print_len += write(1, "-", 1);
	}
	if (nb < 10)
	{
		c = nb + '0';
		print_len += write (1, &c, 1);
	}
	else
	{
		print_len += ft_putnbr(nb / 10);
		print_len += ft_putnbr(nb % 10);
	}
	return (print_len);
}

int	ft_putnbr_ux(const char *base, unsigned int nb)
{
	unsigned int	base_len;
	int				print_len;

	base_len = ft_strlen(base);
	print_len = 0;
	if (nb < base_len)
		print_len += write(1, &base[nb], 1);
	else
	{
		print_len += ft_putnbr_ux(base, nb / base_len);
		print_len += ft_putnbr_ux(base, nb % base_len);
	}
	return (print_len);
}

int	ft_putnbr_p(unsigned long long nb)
{
	int	print_len;

	print_len = 0;
	if (nb < 16)
		print_len += write (1, &"0123456789abcdef"[nb], 1);
	else
	{
		print_len += ft_putnbr_p(nb / 16);
		print_len += ft_putnbr_p(nb % 16);
	}
	return (print_len);
}
