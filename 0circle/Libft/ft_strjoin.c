/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 13:23:40 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/19 15:57:48 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
