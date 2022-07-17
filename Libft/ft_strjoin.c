/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 13:23:40 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/17 13:34:09 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		str_idx;
	int		idx;
	int		len;
	char	*str;

	idx = 0;
	str_idx = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	else
	{
		if (len != 0)
		{
			while (s1[idx])
				str[str_idx++] = s1[idx++];
			idx = 0;
			while (s2[idx])
				str[str_idx++] = s2[idx++];
		}
		str[str_idx] = '\0';
	}
	return (str);
}
