/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:28:01 by gaeokim           #+#    #+#             */
/*   Updated: 2023/01/08 16:41:50 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->collect = 0;
	game->exit = -1;
	game->position = -1;
}

void	init_param(t_game *game, t_player *param)
{
	param->position = game->position;
	param->move = 0;
	param->collect = 0;
}

void	init_image(t_game game, t_image *image)
{
	image->empty = mlx_xpm_file_to_image(game.mlx_ptr, "./img/empty.xpm",
			&image->width, &image->height);
	image->wall = mlx_xpm_file_to_image(game.mlx_ptr, "./img/wall.xpm",
			&image->width, &image->height);
	image->collect = mlx_xpm_file_to_image(game.mlx_ptr, "./img/collect.xpm",
			&image->width, &image->height);
	image->player = mlx_xpm_file_to_image(game.mlx_ptr, "./img/player.xpm",
			&image->width, &image->height);
	image->exit = mlx_xpm_file_to_image(game.mlx_ptr, "./img/exit.xpm",
			&image->width, &image->height);
}

