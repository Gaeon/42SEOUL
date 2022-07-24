/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:28:36 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/24 18:11:26 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(int c)
{
	int	len;

	len = write(1, &c, 1);
	return (len);
}

int	ft_print_s(char	*str)
{
	int	len;

	if (str == 0)
		len = write(1, "(NULL)", 6);
	else
		len = write(1, str, ft_strlen(str));
	return (len);
}

int	ft_print_diu(int nbr)
{
	int	len;

	return (len);
}
