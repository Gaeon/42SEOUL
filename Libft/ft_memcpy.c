/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:03:48 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/19 17:22:46 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			cnt;
	unsigned char	*temp_dst;
	unsigned char	*temp_src;

	cnt = 0;
	if (!n || dst == src)
		return (dst);
	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	while (cnt < n)
	{
		temp_dst[cnt] = temp_src[cnt];
		cnt++;
	}
	return (temp_dst);
}
