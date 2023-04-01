/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:30:30 by gaeokim           #+#    #+#             */
/*   Updated: 2023/04/01 22:15:08 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	cnt;

	cnt = 0;
	if (s != 0)
		cnt += write(fd, s, ft_strlen(s));
	cnt += write(fd, "\n", 1);
	return (cnt);
}
