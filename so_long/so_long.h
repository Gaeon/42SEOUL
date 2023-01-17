/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:32:54 by gaeokim           #+#    #+#             */
/*   Updated: 2023/01/17 14:47:08 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>

# include "mlx/mlx.h"
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 49152
# endif

# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_game{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
	char	*map;
	int		collect;
	int		exit;
	int		position;

	void	*img_empty;
	void	*img_wall;
	void	*img_col;
	void	*img_player;
	void	*img_exit;
	int		img_width;
	int		img_height;

	int		p_move;
	int		p_col;

}	t_game;

//so_long_util.c
int		ft_strlen_without_newline(const char *s);
int		ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strjoin_free(char *s1, char *s2);

//so_long_init.c
void	init_game(t_game *game);
void	init_param(t_game *game);
void	init_image(t_game *game);

//so_long_map.c
void	map_read(char *filename, t_game *game);
int		wall_check(t_game *game);
int		component_check(t_game *game);
void	map_check(t_game *game);
void	draw_map(t_game game);

//so_long_root_check.c
void	dfs(t_game *game, int *visit, int pos);
int		valid_check(t_game *game, int *visit);
int		root_check(t_game *game);

//move.c
int		key_press(int keycode, t_game *game);
void	move_w(t_game *game);
void	move_a(t_game *game);
void	move_s(t_game *game);
void	move_d(t_game *game);

//window.c
int		exit_game(t_game *game);
void	error_message(t_game *game, int fd, int num);

#endif