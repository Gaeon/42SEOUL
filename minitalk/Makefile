# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/19 13:11:31 by gaeokim           #+#    #+#              #
#    Updated: 2022/11/27 19:55:37 by gaeokim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = minitalk
SERVER = server
CLIENT = client

HEADER  = ./minitalk.h

S_SRCS =	./server.c \
			./ft_printf.c \
			./ft_printf_util.c \
			./ft_printf_format.c
S_OBJS = $(S_SRCS:.c=.o)

C_SRCS =	./client.c \
			./util.c
C_OBJS =	$(C_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(SERVER) $(CLIENT)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

$(SERVER): $(S_OBJS)
	$(CC) $(S_OBJS) -o $(SERVER)

$(CLIENT): $(C_OBJS)
	$(CC) $(C_OBJS) -o $(CLIENT)

clean :
	rm -f $(S_OBJS) $(C_OBJS)

fclean :	clean
	rm -f $(SERVER) $(CLIENT)

re :	fclean all

.PHONY : all clean fclean re
