/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:51:26 by gaeokim           #+#    #+#             */
/*   Updated: 2022/11/20 16:44:52 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "so_long.h"
#include "so_long.h"

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "hello world");
	mlx_loop(mlx);
}
