/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:55:43 by gaeokim           #+#    #+#             */
/*   Updated: 2022/09/25 17:53:12 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int		idx;
	int		sign;
	long	ret;

	idx = 0;
	sign = 1;
	ret = 0;
	while ((9 <= str[idx] && str[idx] <= 13) || str[idx] == 32)
		idx++;
	if (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			sign = -1;
		idx++;
	}
	while ('0' <= str[idx] && str[idx] <= '9')
	{
		ret = ret * 10 + str[idx] - '0';
		if (sign == 1 && ret > 2147483647)
			return (-1);
		else if (sign == -1 && ret > 2147483648)
			return (0);
		idx++;
	}
	return ((int)sign * ret);
}
