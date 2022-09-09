/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:41:54 by gaeokim           #+#    #+#             */
/*   Updated: 2022/09/04 18:29:37 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>	//open
# include <limits.h>	//OPEN_MAX
# include <stdlib.h>	//malloc, free

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 49152
# endif

//get_next_line.c
char	*ft_backup(char *read_line);
char	*ft_read(int fd, char *read_line, char *buffer);
char	*get_next_line(int fd);

//get_next_line_util.c
char	*ft_strdup(const char *src);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
