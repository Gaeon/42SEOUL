/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:56:14 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/21 18:00:39 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;
	char	*ret;
	int		fd;

	fd = open("gnl.txt", O_RDONLY);
	while ((ret = get_next_line(fd)) > 0)
	{
		printf("line = %s\n", line);
		free(line);
	}
	free(line);
}
