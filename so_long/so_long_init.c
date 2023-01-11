/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:28:01 by gaeokim           #+#    #+#             */
/*   Updated: 2023/01/11 12:56:57 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->collect = 0;
	game->exit = -1;
	game->position = -1;
}

void	init_param(t_game *game)
{
	game->p_move = 0;
	game->p_col = 0;
}

void	init_image(t_game *game)
{
	game->img_empty = mlx_xpm_file_to_image(game->mlx_ptr, "./img/empty.xpm",
			&game->img_width, &game->img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx_ptr, "./img/wall.xpm",
			&game->img_width, &game->img_height);
	game->img_col = mlx_xpm_file_to_image(game->mlx_ptr, "./img/collect.xpm",
			&game->img_width, &game->img_height);
	game->img_player = mlx_xpm_file_to_image(game->mlx_ptr, "./img/player.xpm",
			&game->img_width, &game->img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx_ptr, "./img/exit.xpm",
			&game->img_width, &game->img_height);
}

