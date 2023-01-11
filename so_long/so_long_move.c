/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:07:45 by gaeokim           #+#    #+#             */
/*   Updated: 2023/01/11 15:29:49 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	if (keycode == KEY_W)
		move_w(game);
	if (keycode == KEY_A)
		move_a(game);
	if (keycode == KEY_S)
		move_s(game);
	if (keycode == KEY_D)
		move_d(game);
	return (0);
}

void	move_w(t_game *game)
{
	if (game->map[game->position - (game->width + 1)] == 'C')
		game->p_col++;
	if (game->map[game->position - (game->width + 1)] == 'E'
		&& game->p_col == game->collect)
		exit_game(game);
	else if (game->map[game->position - (game->width + 1)] != '1'
		&& game->map[game->position - (game->width + 1)] != 'E')
	{
		game->map[game->position] = '0';
		game->position -= game->width + 1;
		game->map[game->position] = 'P';
		game->p_move++;
		ft_printf("%d\n", game->p_move);
		draw_map(*game);
	}
}

void	move_a(t_game *game)
{
	if (game->map[game->position - 1] == 'C')
		game->p_col++;
	if (game->map[game->position - 1] == 'E'
		&& game->p_col == game->collect)
		exit_game(game);
	else if (game->map[game->position - 1] != '1'
		&& game->map[game->position - 1] != 'E')
	{
		game->map[game->position] = '0';
		game->position--;
		game->map[game->position] = 'P';
		game->p_move++;
		ft_printf("%d\n", game->p_move);
		draw_map(*game);
	}
}

void	move_s(t_game *game)
{
	if (game->map[game->position + (game->width + 1)] == 'C')
		game->p_col++;
	if (game->map[game->position + (game->width + 1)] == 'E'
		&& game->p_col == game->collect)
		exit_game(game);
	else if (game->map[game->position + (game->width + 1)] != '1'
		&& game->map[game->position + (game->width + 1)] != 'E')
	{
		game->map[game->position] = '0';
		game->position += game->width + 1;
		game->map[game->position] = 'P';
		game->p_move++;
		ft_printf("%d\n", game->p_move);
		draw_map(*game);
	}
}

void	move_d(t_game *game)
{
	if (game->map[game->position + 1] == 'C')
		game->p_col++;
	if (game->map[game->position + 1] == 'E'
		&& game->p_col == game->collect)
		exit_game(game);
	else if (game->map[game->position + 1] != '1'
		&& game->map[game->position + 1] != 'E')
	{
		game->map[game->position] = '0';
		game->position++;
		game->map[game->position] = 'P';
		game->p_move++;
		ft_printf("%d\n", game->p_move);
		draw_map(*game);
	}
}
