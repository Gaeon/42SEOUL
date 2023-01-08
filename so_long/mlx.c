/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:07:45 by gaeokim           #+#    #+#             */
/*   Updated: 2023/01/08 18:49:06 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_game *game, t_player *param, t_image img)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	if (keycode == KEY_W)
		move_w(game, param, img);
	if (keycode == KEY_A)
		move_a(game, param, img);
	if (keycode == KEY_S)
		move_s(game, param, img);
	if (keycode == KEY_D)
		move_d(game, param, img);
	return (0);
}

void	move_w(t_game *game, t_player *param, t_image img)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(game->map))
	{
		if (game->map[i] == 'P')
			break ;
	}
	if (game->map[i - (game->width + 1)] == 'C')
		param->collect++;
	if (game->map[i - (game->width + 1)] == 'E'
		&& game->collect == param->collect)
		clear_game(game);
	else if (game->map[i - (game->width + 1)] != '1'
		&& game->map[i - (game->width + 1)] != 'E')
	{
		game->map[i] = '0';
		game->map[i - (game->width + 1)] = 'P';
		param->move++;
		ft_printf("%d\n", param->move);
		draw_map(*game, img);
	}
}

// void	move_a(t_game *game, t_player *param, t_image img)
// {
// 	int	i;

// 	i = 0;
// 	while (i++ < ft_strlen(game->map))
// 	{
// 		if (game->map[i] == 'P')
// 			break ;
// 	}
// 	if (game->map[i--] == 'C')
// 		param->collect++;
// 	if (game->map[i - (game->width + 1)] == 'E'
// 		&& game->collect == param->collect)
// 		clear_game(game);
// 	else if (game->map[i--] != '1'
// 		&& game->map[i--] != 'E')
// 	{
// 		game->map[i] = '0';
// 		game->map[i - (game->width + 1)] = 'P';
// 		param->move++;
// 		ft_printf("%d\n", param->move);
// 		draw_map(*game, img);
// 	}
// }

// void	move_s(t_game *game, t_player *param, t_image img)
// {
// 	int	i;

// 	i = 0;
// 	while (i++ < ft_strlen(game->map))
// 	{
// 		if (game->map[i] == 'P')
// 			break ;
// 	}
// 	if (game->map[i - (game->width + 1)] == 'C')
// 		param->collect++;
// 	if (game->map[i - (game->width + 1)] == 'E'
// 		&& game->collect == param->collect)
// 		clear_game(game);
// 	else if (game->map[i - (game->width + 1)] != '1'
// 		&& game->map[i - (game->width + 1)] != 'E')
// 	{
// 		game->map[i] = '0';
// 		game->map[i - (game->width + 1)] = 'P';
// 		param->move++;
// 		ft_printf("%d\n", param->move);
// 		draw_map(*game, img);
// 	}
// }

// void	move_d(t_game *game, t_player *param, t_image img)
// {
// 	int	i;

// 	i = 0;
// 	while (i++ < ft_strlen(game->map))
// 	{
// 		if (game->map[i] == 'P')
// 			break ;
// 	}
// 	if (game->map[i - (game->width + 1)] == 'C')
// 		param->collect++;
// 	if (game->map[i - (game->width + 1)] == 'E'
// 		&& game->collect == param->collect)
// 		clear_game(game);
// 	else if (game->map[i - (game->width + 1)] != '1'
// 		&& game->map[i - (game->width + 1)] != 'E')
// 	{
// 		game->map[i] = '0';
// 		game->map[i - (game->width + 1)] = 'P';
// 		param->move++;
// 		ft_printf("%d\n", param->move);
// 		draw_map(*game, img);
// 	}
// }
