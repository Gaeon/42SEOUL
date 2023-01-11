/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:54:39 by gaeokim           #+#    #+#             */
/*   Updated: 2023/01/11 15:58:22 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_without_newline(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\n' && s[len] != '\0')
		len++;
	return (len);
}

int	ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx;
	size_t	offset;

	idx = 0;
	offset = 0;
	if (needle[0] == '\0')
		return (0);
	while (haystack[idx] != '\0' && idx < len)
	{
		if (haystack[idx] == needle[offset])
		{
			offset++;
			if (needle[offset] == '\0')
				return (1);
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
