/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:56:46 by gaeokim           #+#    #+#             */
/*   Updated: 2022/11/27 20:09:21 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	mandelbrot(int count_w, int count_h, int iter)
{
	double	c_re;
	double	c_im;
	double	x;
	double	x_new;
	double	y;

	c_re = ((count_w - WIN_WIDTH / 2) * 3.0 / WIN_WIDTH) - 0.5;
	c_im = ((WIN_HEIGHT / 2) - count_h) * 2.0 / WIN_HEIGHT;
	x = 0;
	y = 0;
	while ((pow(x, 2.0) + pow(y, 2.0) < 4) && (iter < ITER_MAX))
	{
		x_new = pow(x, 2.0) - pow(y, 2.0) + c_re;
		y = 2 * x * y + c_im;
		x = x_new;
		iter++;
	}
	return (iter);
}

int	julia(int count_w, int count_h, int iter)
{
	double	c_re;
	double	c_im;
	double	x;
	double	x_new;
	double	y;

	c_re = -0.75;
	c_im = 0;
	x = ((count_w - WIN_WIDTH / 2) * 4.0 / WIN_WIDTH);
	y = ((WIN_HEIGHT / 2) - count_h) * 4.0 / WIN_HEIGHT;
	while ((pow(x, 2.0) + pow(y, 2.0) < 4) && (iter < ITER_MAX))
	{
		x_new = pow(x, 2.0) - pow(y, 2.0) + c_re;
		y = 2 * x * y + c_im;
		x = x_new;
		iter++;
	}
	return (iter);
}

int	win_init(t_mlx *mlx)
{
	if (!(mlx->mlx_ptr = mlx_init()))
		return (0);
	if (!(mlx->win_ptr = mlx_new_window
			(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "title")))
		return (0);
	if (!(mlx->img.img_ptr = mlx_new_image
			(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT)))
		return (0);
	if (!(mlx->img.data = mlx_get_data_addr
			(mlx->img.img_ptr, &mlx->img.bpp,
				&mlx->img.size_l, &mlx->img.endian)))
		return (0);
	return (1);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->data + (x * img->bpp / 8) + (y * img->size_l);
	*(unsigned int *)dst = color;
}

void	put_pixel(t_img *img, int type)
{
	int	iter;
	int	count_w;
	int	count_h;

	count_h = -1;
	while (++count_h <= WIN_HEIGHT)
	{
		count_w = -1;
		while (++count_w <= WIN_WIDTH)
		{
			if (type == 1)
				iter = mandelbrot(count_w, count_h, 0);
			else
				iter = julia(count_w, count_h, 0);
			if (iter < ITER_MAX)
				my_mlx_pixel_put(img, count_w, count_h, 0x00ffffff);
			else
				my_mlx_pixel_put(img, count_w, count_h, 0x00000000);
		}
	}
}

int	key_press(int keycode)
{
	if (keycode == KEY_ESC)
		exit(0);
	else
		return (0);
	return (0);
}

int	close(int keycode)
{
	keycode = 0;
	exit(0);
}

int	main(void)
{
	t_mlx	mlx;
	int		type;

	printf("select type > 1: mandelbrot  2: julia\n");
	scanf("%d", &type);
	if (!win_init(&mlx))
		return (0);
	put_pixel(&mlx.img, type);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img.img_ptr, 0, 0);
	mlx_hook(mlx.win_ptr, KEY_PRESS, 0, key_press, 0);
	mlx_hook(mlx.win_ptr, KEY_EXIT, 0, close, 0);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
