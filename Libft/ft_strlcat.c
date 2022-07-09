/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:45:48 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/09 17:51:41 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;
	size_t	dstlen;
	size_t	srclen;

	idx = 0;
	dstlen = 0;
	srclen = 0;
	while (dst[dstlen] != '\0')
		dstlen++;
	while (src[srclen] != '\0')
		srclen++;
	if (dstsize > dstlen)
	{
		while (idx < (dstsize - dstlen - 1) && src[idx] != '\0')
		{
			dst[dstlen + idx] = src[idx];
			idx++;
		}
		dst[dstlen + idx] = '\0';
		return (dstlen + srclen);
	}
	return (dstsize + srclen);
}
