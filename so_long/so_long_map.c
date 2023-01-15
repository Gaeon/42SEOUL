/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:08:08 by gaeokim           #+#    #+#             */
/*   Updated: 2023/01/15 16:58:44 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_read(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		error_message(fd, 3);
	line = get_next_line(fd);
	game->height++;
	game->width = ft_strlen_without_newline(line);
	game->map = ft_strdup(line);
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		if (line)
		{
			if (game->width != ft_strlen_without_newline(line))
				error_message(fd, 4);
			game->map = ft_strjoin(game->map, line);
			game->height++;
		}
	}
	close(fd);
}

int	wall_check(t_game *game)
{
	int	idx;
	int	check_idx;

	idx = 0;
	while (idx < game->height)
	{
		if (idx == 0 || idx == game->height - 1)
		{
			check_idx = idx * (game->width + 1);
			while (check_idx < (idx + 1) * (game->width + 1) - 1)
			{
				if (game->map[check_idx] != '1')
					return (-1);
				check_idx++;
			}
		}
		else
		{
			if (game->map[idx * (game->width + 1)] != '1'
				|| game->map[(idx + 1) * (game->width + 1) - 2] != '1')
				return (-1);
		}
		idx++;
	}
	return (1);
}

int	component_check(t_game *game)
{
	int	idx;

	idx = -1;
	while (game->map[++idx] != '\0')
	{
		if (game->map[idx] == 'C')
			game->collect++;
		else if (game->map[idx] == 'E' && game->exit == -1)
			game->exit = idx;
		else if (game->map[idx] == 'P' && game->position == -1)
			game->position = idx;
		else if (game->map[idx] != '\n' && game->map[idx] != '0'
			&& game->map[idx] != '1')
			return (-1);
	}
	if (game->collect < 1 || game->exit == -1 || game->position == -1)
		return (-1);
	return (1);
}

void	map_check(t_game *game)
{
	if (wall_check(game) != 1)
		error_message(0, 5);
	if (component_check(game) != 1)
		error_message(0, 6);
	if (root_check(game) != 1)
		error_message(0, 7);
}

void	draw_map(t_game game)
{
	int		hei;
	int		wid;

	hei = -1;
	while (++hei < game.height)
	{
		wid = -1;
		while (++wid < game.width)
		{
			mlx_put_image_to_window(game.mlx_ptr, game.win_ptr,
				game.img_empty, wid * 64, hei * 64);
			if (game.map[hei * (game.width + 1) + wid] == '1')
				mlx_put_image_to_window(game.mlx_ptr, game.win_ptr,
					game.img_wall, wid * 64, hei * 64);
			else if (game.map[hei * (game.width + 1) + wid] == 'C')
				mlx_put_image_to_window(game.mlx_ptr, game.win_ptr,
					game.img_col, wid * 64, hei * 64);
			else if (game.map[hei * (game.width + 1) + wid] == 'P')
				mlx_put_image_to_window(game.mlx_ptr, game.win_ptr,
					game.img_player, wid * 64, hei * 64);
			else if (game.map[hei * (game.width + 1) + wid] == 'E')
				mlx_put_image_to_window(game.mlx_ptr, game.win_ptr,
					game.img_exit, wid * 64, hei * 64);
		}
	}
}
