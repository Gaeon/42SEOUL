/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:32:54 by gaeokim           #+#    #+#             */
/*   Updated: 2022/12/29 16:59:39 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>

# include "./minilibx-linux/mlx.h"

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

//ft_printf.c
int		ft_format(char c, va_list ap);
int		ft_printf(const char *str, ...);
int		ft_print_c(int c);
int		ft_print_s(char *str);
int		ft_print_di(int nbr);

//get_next_line.c
char	*ft_backup(char *read_line);
char	*ft_read(int fd, char *read_line, char *buffer);
char	*get_next_line(int fd);

//ft_printf_util.c
size_t	ft_strlen(const char *s);
int		ft_putnbr(int nb);

//get_next_line_util.c
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

//so_long_util.c
size_t	ft_strlen_without_newline(const char *s);

//so_long_init.c
void	init_game(t_game *game);
void	init_param(t_game *game, t_player *param);
void	init_image(t_game *game, t_image *image);

//so_long_map.c
int		map_read(char *filename, t_game *game);
int		wall_check(t_game *game);
int		component_check(t_game *game);
int		root_check(t_game *game);
int		map_check(t_game *game);
void	draw_map(t_game game, t_image img);

#endif