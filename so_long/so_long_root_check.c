/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_root_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:03:45 by gaeokim           #+#    #+#             */
/*   Updated: 2023/02/21 13:19:34 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dfs(t_game *game, int *visit, int pos)
{	
	if (game->map[pos] == 'E')
		return ;
	if (game->map[pos + 1] != '1' && visit[pos + 1] != 1)
	{
		visit[pos + 1] = 1;
		dfs(game, visit, pos + 1);
	}
	if (game->map[pos - 1] != '1' && visit[pos - 1] != 1)
	{
		visit[pos - 1] = 1;
		dfs(game, visit, pos - 1);
	}
	if (game->map[pos + (game->width + 1)] != '1'
		&& visit[pos + (game->width + 1)] != 1)
	{
		visit[pos + (game->width + 1)] = 1;
		dfs(game, visit, pos + (game->width + 1));
	}
	if (game->map[pos - (game->width + 1)] != '1'
		&& visit[pos - (game->width + 1)] != 1)
	{
		visit[pos - (game->width + 1)] = 1;
		dfs(game, visit, pos - (game->width + 1));
	}
}

int	valid_check(t_game *game, int *visit)
{
	int	idx;
	int	collect;
	int	exit;

	idx = -1;
	collect = 0;
	exit = 0;
	while (++idx < (int)ft_strlen(game->map))
	{
		if (visit[idx] == 1)
		{
			if (game->map[idx] == 'C')
				collect++;
			if (game->map[idx] == 'E')
				exit++;
		}
	}
	if (collect == game->collect && exit == 1)
		return (1);
	else
		return (-1);
}

int	root_check(t_game *game)
{
	int	idx;
	int	*visit;

	idx = -1;
	visit = (int *)malloc(sizeof(int) * ft_strlen(game->map));
	while (++idx < (int)ft_strlen(game->map))
		visit[idx] = 0;
	idx = game->position;
	dfs(game, visit, idx);
	idx = valid_check(game, visit);
	free(visit);
	return (idx);
}
