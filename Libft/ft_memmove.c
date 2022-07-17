/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:13:44 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/17 16:26:07 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	cnt;
	char	*temp_dst;
	char	*temp_src;

	cnt = -1;
	temp_dst = (char *)dst;
	temp_src = (char *)src;
	if (!dst && !src)
		return (0);
	if (temp_dst < temp_src)
		while (++cnt < len)
			temp_dst[cnt] = temp_src[cnt];
	else
		while (++cnt < len)
			temp_dst[len - cnt - 1] = temp_src[len - cnt - 1];
	return (temp_dst);
}
