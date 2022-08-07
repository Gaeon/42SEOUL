/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:23:22 by gaeokim           #+#    #+#             */
/*   Updated: 2022/08/07 15:00:24 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_backup(char *read_line)
{
	int		idx;

	idx = 0;
	while (read_line[idx])
	{
		if (read_line[idx] == '\n')
			return (ft_substr(read_line, idx + 1, ft_strlen(read_line) - idx));
		idx++;
	}
	return (0);
}

char	*ft_line(char *read_line)
{
	int		idx;

	idx = 0;
	while (read_line[idx])
	{
		if (read_line[idx] == '\n')
			return (ft_substr(read_line, 0, idx));
	}
	return (0);
}

char	*ft_read(int fd, char *read_line, char *buffer)
{
	char	*temp;
	int		read_byte;

	read_byte = 1;
	while (read_byte)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == 0)
			break ;
		else if (read_byte == -1)
			return (0);
		buffer[BUFFER_SIZE] = '\0';
		if (!read_line)
		{
			read_line = ft_strdup("");
			if (!read_line)
				return (0);
		}
		temp = read_line;
		read_line = ft_strjoin(buffer, temp);
		free(temp);
		if (!read_line)
			return (0);
		if (ft_strchr(read_line, '\n'))
			return (read_line);
	}
	return (read_line);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buffer;
	char		*read_line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	read_line = 0;
	if (!buffer)
		return (0);
	read_line = ft_read(fd, read_line, buffer);
	backup = ft_backup(read_line);
	read_line = ft_line(read_line);
	return (read_line);
}
