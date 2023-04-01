/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:52:14 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/24 18:03:31 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx;
	size_t	offset;

	idx = 0;
	offset = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[idx] != '\0' && idx < len)
	{
		if (haystack[idx] == needle[offset])
		{
			offset++;
			if (needle[offset] == '\0')
				return ((char *)&haystack[idx - offset + 1]);
		}
		else
		{
			idx -= offset;
			offset = 0;
		}
		idx++;
	}
	return (0);
}
