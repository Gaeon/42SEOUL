/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:07:45 by gaeokim           #+#    #+#             */
/*   Updated: 2023/01/08 16:57:53 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_game *game, t_player *param)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	if (keycode == KEY_W)
		move_w(game, param);
	if (keycode == KEY_A)
		move_a(game, param);
	if (keycode == KEY_S)
		move_s(game, param);
	if (keycode == KEY_D)
		move_d(game, param);
	return (0);
}

void	move_w(t_game *game, t_player *param)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(game->map))
	{
		if (game->map[i] == 'P')
			break ;
	}
	if (game->map[i - game->width] == 'C')
		param->collect++;
	if (game->map[i - game->width] == 'E' && game->collect == param->collect)
		clear_game(game);
	else if (game->map[i - game->width] != '1' && game->map[i - game->width] != 'E')
	{
		game->map[i] = '0';
		game->map[i - game->width] = 'P';
		param->move++;
		ft_printf("%d\n", param->move);
		draw_map(game, img);
	}
}
