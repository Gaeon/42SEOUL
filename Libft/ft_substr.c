/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 13:10:56 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/19 19:58:01 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
