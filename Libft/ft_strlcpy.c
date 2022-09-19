/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:35:55 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/21 14:19:12 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;
	size_t	srcsize;

	idx = 0;
	srcsize = 0;
	while (src[srcsize] != '\0')
		srcsize++;
	if (dstsize != 0)
	{
		while (src[idx] && idx < (dstsize - 1))
		{
			dst[idx] = src[idx];
			idx++;
		}
		dst[idx] = '\0';
	}
	return (srcsize);
}
