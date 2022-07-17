/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 16:03:48 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/17 16:17:06 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t	cnt;
	char	*temp_dst;
	char	*temp_src;

	cnt = 0;
	if (!n || dst == src)
		return (dst);
	temp_dst = (char *)dst;
	temp_src = (char *)src;
	while (cnt < n)
	{
		temp_dst[cnt] = temp_src[cnt];
		cnt++;
	}
	return (temp_dst);
}
