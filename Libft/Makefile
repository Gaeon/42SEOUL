# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 19:10:56 by gaeokim           #+#    #+#              #
#    Updated: 2022/07/09 18:07:14 by gaeokim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a
HEADER  = ./libft.h
SRCS = 	./ft_isalpha.c \
		./ft_isdigit.c \
		./ft_isalnum.c \
		./ft_isascii.c \
		./ft_isprint.c \
		./ft_strlen.c \
		./ft_memset.c \
		./ft_bzero.c \
		./ft_memcpy.c \
		./ft_memmove.c \
		./ft_strlcpy.c \
		./ft_strlcat.c \
		./ft_strncmp.c \
		./ft_toupper.c \
		./ft_tolower.c \
		./ft_strchr.c \
		./ft_strrchr.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

.c.o :
	$(CC) $(CFLAG) -c -o $(<:.c=.o) $<

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(OBJS) $(NAME)

re :	fclean all