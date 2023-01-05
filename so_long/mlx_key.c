/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:07:45 by gaeokim           #+#    #+#             */
/*   Updated: 2022/12/29 18:06:18 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_game game, t_player *param)
{
	if (keycode == KEY_W)
		param->position -= game.width + 1;
	else if (keycode == KEY_S)
		param->position += game.width + 1;
	else if (keycode == KEY_A)
		param->position -= 1;
	else if (keycode == KEY_D)
		param->position += 1;
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}
