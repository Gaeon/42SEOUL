/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:34:17 by gaeokim           #+#    #+#             */
/*   Updated: 2022/12/29 12:32:05 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	ft_format(char c, va_list ap)
{
	if (c == 'c')
		return (ft_print_c(va_arg(ap, int)));
	else if (c == 's')
		return (ft_print_s(va_arg(ap, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_print_di(va_arg(ap, int)));
	else
		return (write(1, "%", 1));
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		idx;
	int		len;

	idx = 0;
	len = 0;
	va_start(ap, str);
	while (str[idx])
	{
		if (str[idx] == '%')
			len += ft_format(str[++idx], ap);
		else
			len += write(1, &str[idx], 1);
		idx++;
	}
	va_end(ap);
	return (len);
}
