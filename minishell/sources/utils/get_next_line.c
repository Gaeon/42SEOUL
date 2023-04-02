/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:23:22 by gaeokim           #+#    #+#             */
/*   Updated: 2023/04/02 15:01:16 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_backup(char *read_line)
{
	int		idx;
	char	*temp;

	idx = 0;
	while (read_line[idx])
	{
		if (read_line[idx] == '\n')
			break ;
		idx++;
	}
	if (read_line[idx] == '\0')
		return (0);
	temp = ft_substr(read_line, idx + 1, ft_strlen(read_line) - idx);
	if (!temp)
		return (0);
	if (temp[0] == '\0')
	{
		free(temp);
		temp = 0;
		return (0);
	}
	read_line[idx + 1] = '\0';
	return (temp);
}

char	*ft_read(int fd, char *backup, char *buffer)
{
	char	*temp;
	int		read_byte;

	read_byte = 1;
	while (read_byte)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == 0)
			break ;
		if (read_byte == -1)
			return (0);
		buffer[read_byte] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(temp, buffer);
		if (!backup)
			return (0);
		free(temp);
		temp = 0;
		if (ft_strchr(backup, '\n'))
			break ;
	}
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buffer;
	char		*read_line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	read_line = ft_read(fd, backup, buffer);
	free(buffer);
	buffer = 0;
	if (!read_line)
		return (0);
	backup = ft_backup(read_line);
	return (read_line);
}
