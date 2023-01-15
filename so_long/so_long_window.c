/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:10:32 by gaeokim           #+#    #+#             */
/*   Updated: 2023/01/15 16:58:48 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(0);
}

void	error_message(int fd, int num)
{
	if (num == 1)
		ft_printf("Error! No Map Input\n");
	else if (num == 2)
		ft_printf("Error! A file is not ending with the .ber extension.\n");
	else if (num == 3)
		ft_printf("Error! No such file or directory!\n");
	else if (num == 4)
	{
		ft_printf("Error! Map is not ractangle!\n");
		close(fd);
	}
	else if (num == 5)
		ft_printf("Error! Map is not surrounded by walls!\n");
	else if (num == 6)
		ft_printf("Error! Component Error!\n");
	else if (num == 7)
		ft_printf("Error! There are no valid path in the map!\n");
	exit(1);
}
