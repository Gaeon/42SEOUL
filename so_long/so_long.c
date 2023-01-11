/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:14:10 by gaeokim           #+#    #+#             */
/*   Updated: 2023/01/11 16:01:21 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	extension_check(char *str)
{
	int	idx;

	idx = ft_strlen(str);
	if (ft_strnstr(&str[idx - 4], ".ber", 4) != 1)
	{
		ft_printf("Error! A file is not ending with the .ber extension.\n");
		exit(0);
	}
}

int	main(int argc, char *argv[])
{
	t_game		game;

	init_game(&game);
	if (argc != 2)
	{
		ft_printf("Error! No Map Input\n");
		return (0);
	}
	extension_check(argv[1]);
	map_read(argv[1], &game);
	map_check(&game);
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr,
			game.width * 64, game.height * 64, "so_long");
	init_param(&game);
	init_image(&game);
	mlx_hook(game.win_ptr, X_EVENT_KEY_EXIT, 0, &exit_game, &game);
	mlx_hook(game.win_ptr, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	draw_map(game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
