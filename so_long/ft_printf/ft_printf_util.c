/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyerimki <hyerimki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:00:42 by gaeokim           #+#    #+#             */
/*   Updated: 2023/01/05 17:57:20 by hyerimki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
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
