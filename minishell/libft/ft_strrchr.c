/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 18:08:05 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/21 15:07:52 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		idx;
	char	chr;

	chr = (char)c;
	idx = ft_strlen(s);
	if (chr == '\0')
		return ((char *)&s[idx]);
	while (idx >= 0)
	{
		if (s[idx] == chr)
			return ((char *)&s[idx]);
		idx--;
	}
	return (0);
}
