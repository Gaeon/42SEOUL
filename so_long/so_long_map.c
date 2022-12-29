/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 13:08:08 by gaeokim           #+#    #+#             */
/*   Updated: 2022/12/29 15:25:59 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_read(char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
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
				return (-1);
			game->map = ft_strjoin(game->map, line);
			game->height++;
		}
	}
	close(fd);
	return (1);
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

	idx = 0;
	game->collectible = 0;
	game->exit = 0;
	game->position = 0;
	while (game->map[idx] != '\0')
	{
		if (game->map[idx] == 'C')
			game->collectible++;
		else if (game->map[idx] == 'E')
			game->exit++;
		else if (game->map[idx] == 'P')
			game->position++;
		idx++;
	}
	if (game->collectible < 1 || game->exit != 1 || game->position != 1)
		return (-1);
	return (1);
}

int	root_check(t_game *game)
{
	return (1);
}

int	map_check(t_game *game)
{
	if (wall_check(game) == -1 || component_check(game) == -1)
		return (-1);
	return (1);
}
