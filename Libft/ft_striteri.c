/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 15:17:48 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/19 19:12:04 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int		idx;

	idx = 0;
	if (s == 0 || f == 0)
		return ;
	while (s[idx])
	{
		f(idx, &s[idx]);
		idx++;
	}
}
