/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:14:10 by gaeokim           #+#    #+#             */
/*   Updated: 2022/12/29 16:59:40 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game		game;
	t_player	param;
	t_image		img;

	init_game(&game);
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
	init_param(&game, &param);
	init_image(&game, &img);
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, 500, 500, "so_long");
	draw_map(game, img);
	mlx_loop(game.mlx_ptr);
	return (0);
}
