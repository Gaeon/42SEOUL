/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:55:36 by gaeokim           #+#    #+#             */
/*   Updated: 2022/11/27 20:05:32 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <fcntl.h>		//open()
# include <unistd.h> 	//close() read() write()
# include <stdio.h> 	//printf() perror() strerror()
# include <stdlib.h> 	//malloc() free() exit()

# include "./minilibx_mms/mlx.h"
# include "./minilibx_opengl/mlx.h"

# define KEY_PRESS		2
# define KEY_EXIT		17
# define KEY_ESC		53
# define MOUSE_PRESS 	4
# define MOUSE_MOTION 	6
# define WIN_WIDTH		800
# define WIN_HEIGHT		600
# define ITER_MAX		100

typedef struct s_img{
	void	*img_ptr;
	char	*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_mlx{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_mlx;

//fractol_control.c
int	mandelbrot(int count_w, int count_h, int iter);
int	julia(int count_w, int count_h, int iter, t_img *img);

//fractol_type.c
int	key_press(int keycode);
int	close(int keycode);

#endif
