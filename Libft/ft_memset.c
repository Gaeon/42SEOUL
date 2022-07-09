/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 15:51:14 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/09 16:10:10 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int		cnt;
	char	*temp;

	cnt = 0;
	temp = (char *)b;
	while (cnt < len)
	{
		temp[cnt] = c;
		cnt++;
	}
	return (b);
}
