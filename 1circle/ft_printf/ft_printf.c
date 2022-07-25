/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 15:34:17 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/25 15:18:15 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_input_check(const char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] == '%')
		{
			if (!ft_strchr("cspdiuxX%", str[++idx]))
				return (-1);
		}
		idx++;
	}
	return (1);
}

int	ft_format(char c, va_list ap)
{
	if (c == 'c')
		return (ft_print_c(va_arg(ap, int)));
	else if (c == 's')
		return (ft_print_s(va_arg(ap, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_print_di(va_arg(ap, int)));
	else if (c == 'p')
		return (ft_print_p(va_arg(ap, unsigned long long)));
	else if (c == 'u' || c == 'x' || c == 'X')
		return (ft_print_ux(c, va_arg(ap, unsigned int)));
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
	if (!ft_input_check(str))
		return (-1);
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
