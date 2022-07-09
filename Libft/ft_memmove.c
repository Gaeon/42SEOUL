/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:13:44 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/09 17:16:21 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		cnt;
	char	*ret;
	char	*temp_dst;
	char	*temp_src;

	cnt = 0;
	ret = (char *)dst;
	temp_dst = (char *)dst;
	temp_src = (char *)src;
	while (cnt < len)
	{
		temp_dst[cnt] = temp_src[cnt];
		cnt++;
	}
	return (ret);
}
