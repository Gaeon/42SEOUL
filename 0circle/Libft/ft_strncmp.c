/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:52:22 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/09 17:59:05 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;

	idx = 0;
	if (n == 0)
		return (0);
	while (idx < n && (s1[idx] != '\0' || s2[idx] != '\0'))
	{
		if (s1[idx] == s2[idx])
			idx++;
		else
			return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
	}
	return (0);
}
