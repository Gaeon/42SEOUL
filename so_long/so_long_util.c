/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:54:39 by gaeokim           #+#    #+#             */
/*   Updated: 2023/01/16 16:36:19 by gaeokim          ###   ########.fr       */
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

char	*ft_strjoin_free(char *s1, char *s2)
{
	int		str_idx;
	int		s_idx;
	char	*str;

	s_idx = 0;
	str_idx = 0;
	if (s1 == 0 || s2 == 0)
		return (0);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == 0)
		return (0);
	else
	{
		if (ft_strlen(s1) + ft_strlen(s2) != 0)
		{
			while (s1[s_idx])
				str[str_idx++] = s1[s_idx++];
			s_idx = 0;
			while (s2[s_idx])
				str[str_idx++] = s2[s_idx++];
		}
		str[str_idx] = '\0';
	}
	free(s1);
	return (str);
}
