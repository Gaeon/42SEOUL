/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:59:14 by gaeokim           #+#    #+#             */
/*   Updated: 2022/11/27 20:06:12 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
				iter = julia(count_w, count_h, 0, img);
			if (iter < ITER_MAX)
				my_mlx_pixel_put(img, count_w, count_h, 0x00ffffff);
			else
				my_mlx_pixel_put(img, count_w, count_h, 0x00000000);
		}
	}
}

int	main(void)
{
	t_mlx	mlx;
	int		type;

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
