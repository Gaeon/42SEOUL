#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# include "../printf/ft_printf.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

//get_next_line.c
char	*ft_backup(char *read_line);
char	*ft_read(int fd, char *read_line, char *buffer);
char	*get_next_line(int fd);

//get_next_line_util.c
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif