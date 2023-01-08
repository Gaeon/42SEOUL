/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:32:54 by gaeokim           #+#    #+#             */
/*   Updated: 2023/01/08 18:45:59 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include <mlx.h>

# include "gnl/get_next_line.h"
# include "printf/ft_printf.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 49152
# endif

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_player{
	int	position;
	int	move;
	int	collect;
}	t_player;

typedef struct s_image{
	void	*empty;
	void	*wall;
	void	*collect;
	void	*player;
	void	*exit;
	int		width;
	int		height;
}	t_image;

typedef struct s_game{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
	char	*map;
	int		collect;
	int		exit;
	int		position;
}	t_game;

//so_long_util.c
int		ft_strlen_without_newline(const char *s);

//so_long_init.c
void	init_game(t_game *game);
void	init_param(t_game *game, t_player *param);
void	init_image(t_game game, t_image *image);

//so_long_map.c
int		map_read(char *filename, t_game *game);
int		wall_check(t_game *game);
int		component_check(t_game *game);
int		root_check(t_game *game);
int		map_check(t_game *game);
void	draw_map(t_game game, t_image img);

//mlx.c
int		key_press(int keycode, t_game *game, t_player *param, t_image img);
void	move_w(t_game *game, t_player *param, t_image img);
void	move_a(t_game *game, t_player *param, t_image img);
void	move_s(t_game *game, t_player *param, t_image img);
void	move_d(t_game *game, t_player *param, t_image img);

void	exit_game(t_game *game);
void	clear_game(t_game *game);

#endif