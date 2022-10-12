/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:07:47 by gaeokim           #+#    #+#             */
/*   Updated: 2022/09/25 16:18:27 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_print_c(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_s(char *str)
{
	if (str == 0)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	ft_print_di(int nbr)
{
	return (ft_putnbr(nbr));
}

int	ft_print_p(unsigned long long nbr)
{
	int	print_len;

	print_len = 0;
	print_len += write(1, "0x", 2);
	print_len += ft_putnbr_p(nbr);
	return (print_len);
}

int	ft_print_ux(char c, unsigned int nbr)
{
	int	print_len;

	print_len = 0;
	if (c == 'u')
		print_len += ft_putnbr_ux("0123456789", nbr);
	else if (c == 'X')
		print_len += ft_putnbr_ux("0123456789ABCDEF", nbr);
	else
		print_len += ft_putnbr_ux("0123456789abcdef", nbr);
	return (print_len);
}
