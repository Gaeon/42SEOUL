/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:54:39 by gaeokim           #+#    #+#             */
/*   Updated: 2022/12/29 14:03:07 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen_without_newline(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\n' && s[len] != '\0')
		len++;
	return (len);
}
