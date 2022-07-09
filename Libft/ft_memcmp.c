/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:47:54 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/09 18:51:43 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*str1;
	const char	*str2;
	size_t		idx;

	str1 = (const char *)s1;
	str2 = (const char *)s2;
	idx = 0;
	idx = 0;
	if (n == 0)
		return (0);
	while (idx < n)
	{
		if (str1[idx] == str2[idx])
			idx++;
		else
			return ((unsigned char)str1[idx] - (unsigned char)str2[idx]);
	}
	return (0);
}
