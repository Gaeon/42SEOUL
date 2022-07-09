/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:52:14 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/09 18:54:56 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	idx;
	int	offset;

	idx = 0;
	offset = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[idx] != '\0')
	{
		if (str[idx] == to_find[offset])
		{
			offset++;
			if (to_find[offset] == '\0')
				return (&str[idx - offset + 1]);
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

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx;
	size_t	offset;

	idx = 0;
	offset = 0;
	if (needle[0] == '\0')
		return (haystack);
	while (haystack[idx] != '\0' && idx < len)
	{
		if (haystack[idx] == needle[offset])
		{
			offset++;
			if (needle[offset] == '\0')
				return (&haystack[idx - offset + 1]);
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