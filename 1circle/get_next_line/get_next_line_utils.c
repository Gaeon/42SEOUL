/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:23:41 by gaeokim           #+#    #+#             */
/*   Updated: 2022/09/04 18:10:36 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *src)
{
	int		len;
	char	*dup;

	len = ft_strlen(src);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (dup == 0)
		return (0);
	len = 0;
	while (src[len] != '\0')
	{
		dup[len] = src[len];
		len++;
	}
	dup[len] = '\0';
	return (dup);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
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
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char	chr;

	chr = (char)c;
	while (*s != '\0')
	{
		if (*s == chr)
			return ((char *)s);
		s++;
	}
	if (chr == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	idx;
	char	*substr;

	idx = 0;
	if (s == 0)
		return (0);
	substr = (char *)malloc(len + 1);
	if (substr == 0)
		return (NULL);
	if (start < ft_strlen(s))
	{
		s += start;
		while (s[idx] && idx < len)
		{
			substr[idx] = s[idx];
			idx++;
		}
	}
	substr[idx] = '\0';
	return (substr);
}
