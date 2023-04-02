/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:00:32 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 16:01:32 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

long long	ft_atol(char *str, long long *n)
{
	long long	sign;

	sign = 1;
	*n = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -sign;
	if (*str == '-' || *str == '+')
		str++;
	if (!ft_isdigit(*str))
		return (-1);
	while (ft_isdigit(*str))
	{
		*n = 10 * (*n) + (*str - '0');
		str++;
	}
	if (*str && !ft_isspace(*str))
		return (-1);
	*n *= sign;
	return (0);
}
