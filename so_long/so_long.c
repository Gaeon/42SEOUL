/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:04:10 by gaeokim           #+#    #+#             */
/*   Updated: 2022/12/29 15:15:16 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Error! No Map Input");
		return (0);
	}
	if (map_read(argv[1], &game) == -1 || map_check(&game) == -1)
	{
		ft_printf("Error! Map is not valid");
		return (0);
	}

	return (0);
}
