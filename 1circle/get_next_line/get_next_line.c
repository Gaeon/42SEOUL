/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:23:22 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/26 16:19:04 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *buff, char *backup)
{
	int		read_byte;
	char	*temp;

	read_byte = 1;
	temp = 0;
	while (read_byte)
	{
		read_byte = read(fd, buff, BUFFER_SIZE);
		if (read_byte == 0)
			break ;
		else if (read_byte == -1)
			return (0);
		buff[read_byte] = '\0';
		if (!temp)
			temp = ft_strdup("");
		temp = ft_strjoin(temp, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*backup;
	char		*read_line;

	if (fd < 0 || fd > OPEN_MAX)
		return (0);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!backup)
		return (0);
	read_line = ft_read(fd, buff, backup);
	free(buff);
	return (read_line);
}
