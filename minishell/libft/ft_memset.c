/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:51:14 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/19 14:01:40 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			cnt;
	unsigned char	*temp;

	cnt = 0;
	temp = (unsigned char *)b;
	while (cnt < len)
	{
		temp[cnt] = c;
		cnt++;
	}
	return (b);
}
