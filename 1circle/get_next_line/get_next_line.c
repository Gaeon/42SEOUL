/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:23:22 by gaeokim           #+#    #+#             */
/*   Updated: 2022/08/02 16:08:35 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_backup(char *temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		if (temp[i] == '\n')
			return (ft_substr(temp, 0, i));
		i++;
	}
	return (temp);
}

char	*ft_line(char *temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		if (temp[i] == '\n')
			return (ft_substr(temp, i + 1, ft_strlen(temp) - i - 1));
		i++;
	}
	return (0);
}

char	*ft_read(int fd, char *buff, char *backup)
{
	int		read_byte;
	char	*temp;

	read_byte = 1;
	while (read_byte)
	{
		read_byte = read(fd, buff, BUFFER_SIZE);
		if (read_byte == 0)
			break ;
		else if (read_byte == -1)
			return (0);
		buff[read_byte] = '\0';
		if (!backup)
			backup = ft_strdup("");
		temp = backup;
		backup = ft_strjoin(temp, buff);
		if (!backup)
			return (0);
		if (ft_strchr(backup, '\n'))
			break ;
	}
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buff;
	char		*temp;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (0);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	temp = ft_read(fd, buff, backup);
	free(buff);
	if (temp == 0)
		return (0);
	backup = ft_backup(temp);
	temp = ft_line(temp);
	return (temp);
}
