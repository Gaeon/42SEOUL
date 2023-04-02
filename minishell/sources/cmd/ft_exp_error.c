/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:58:01 by johyyoon          #+#    #+#             */
/*   Updated: 2023/04/02 15:58:46 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_exp_error(int q[3], int *r_n)
{
	if (q[2] >= 2 && *r_n == -2)
	{
		printf("bash: export: not valid in this context\n");
		return (2);
	}
	else
	{
		q[2] = 1;
		return (1);
	}
}
