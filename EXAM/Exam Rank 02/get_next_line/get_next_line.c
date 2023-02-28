#include "get_next_line.h"

char	*ft_strdup(char *buff)
{
	int		len;
	char	*str;

	len = 0;
	while (buff[len])
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	len = 0;
	while (buff[len])
	{
		str[len] = buff[len];
		len++;
	}
	str[len] = 0;
	return (str);
}

char	*get_next_line(int fd)
{
	int 	r;
	int 	idx;
	char	c;
	char	buff[1000000];

	r = 0;
	idx = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	r = read(fd, &c, 1);
	while (r > 0)
	{
		buff[idx++] = c;
		if (c == '\n')
			break ;
		r = read(fd, &c, 1);
	}
	buff[idx] = 0;
	if (idx == 0 || r <= 0)
		return (0);
	return (ft_strdup(buff));
}