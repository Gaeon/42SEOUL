/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:58:02 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/19 14:11:34 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			cnt;
	unsigned char	*temp;

	cnt = 0;
	temp = (unsigned char *)s;
	if (n != 0)
	{
		while (cnt < n)
		{
			temp[cnt] = 0;
			cnt++;
		}
	}
}
