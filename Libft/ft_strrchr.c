/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:08:05 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/09 18:42:06 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	idx;

	idx = 0;
	while (*s != '\0')
	{
		idx++;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	while (idx >= 0)
	{
		if (*s == c)
			return ((char *)s);
		s--;
		idx--;
	}
	return (0);
}
