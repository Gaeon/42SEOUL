/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:39:12 by marvin            #+#    #+#             */
/*   Updated: 2023/02/21 14:58:00 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi_check(const char *str, t_info *info)
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
			print_error(4, info);
		else if (sign == -1 && ret > 2147483648)
			print_error(4, info);
		idx++;
	}
    if (str[idx] != '\0')
        print_error(5, info);
	return ((int)sign * ret);
}