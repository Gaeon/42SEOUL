/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 19:35:58 by gaeokim           #+#    #+#             */
/*   Updated: 2022/11/27 19:39:18 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	exit(0);
}