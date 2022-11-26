/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:51:26 by gaeokim           #+#    #+#             */
/*   Updated: 2022/11/26 21:21:54 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars{
	void	*mlx;
	void	*win;
}	t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 123 || keycode == 0)
		printf("left\n");
	else if (keycode == 124 || keycode == 2)
		printf("right\n");
	else if (keycode == 125 || keycode == 1)
		printf("down\n");
	else if (keycode == 126 || keycode == 13)
		printf("up\n");
	return (0);
}

int	mouse_hook(int button, int x, int y, t_vars *vars){
	if (button == 1)
		printf("left click\n");
	else if (button == 2)
		printf("right click\n");
	else if (button == 3)
		printf("middle click\n");
	else if (button == 4)
		printf("scroll up\n");
	else if (button == 5)
		printf("scroll down\n");
	return (0);
}

int	main(void)
{
	t_vars	vars;
	t_data	img;
	int		img_height;
	int		img_width;
	char	*ground_path = "./image/ground.xpm";
	char	*wall_path = "./image/wall.xpm";
	
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 600, "hello world");
	img.img = mlx_xpm_file_to_image(vars.mlx, ground_path,
			&img_width, &img_height);
	//img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	//my_mlx_pixel_put(&img, 5, 5, 0x00ff0000);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 50, 50);

	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);

	mlx_loop(vars.mlx);
}
