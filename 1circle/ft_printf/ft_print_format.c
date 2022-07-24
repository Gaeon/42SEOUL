/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:28:36 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/22 12:47:39 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_print_cs(const char c, va_list *ap)
{
	char	*str;
	ssize_t	print_len;

	str = va_arg(*ap, char *);
	print_len = 0;
	if (c == 'c')
		print_len = write(1, &str[0], 1);
	else
	{
		if (str == 0)
			print_len = write(1, "(NULL)", 6);
		else
			print_len = write(1, str, ft_strlen(str));
	}
	return (print_len);
}

ssize_t	ft_print_diu(const char c, va_list *ap)
{
	const char	base[11] = "0123456789";
	char		*str;
	long		nbr;
	ssize_t		print_len;

	print_len = 0;
	nbr = (long)va_arg(*ap, int);
	if (c == 'd' || c == 'u')
	{
		str = ft_itoa(nbr);
		print_len = write(1, str, ft_strlen(str));
	}
}
ssize_t	t_print_px(const char c, va_list *ap);
ssize_t	ft_print_X(const char c, va_list *ap);