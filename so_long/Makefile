# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 19:31:58 by gaeokim           #+#    #+#              #
#    Updated: 2023/01/05 18:11:22 by gaeokim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ./main.c						\
		./so_long_init.c			\
		./so_long_map.c				\
		./so_long_util.c			\
		./mlx.c						\
		printf/ft_printf.c			\
		printf/ft_printf_util.c		\
		gnl/get_next_line.c			\
		gnl/get_next_line_util.c
OBJS = $(SRC:.c=.o)
NAME = so_long

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} -lmlx -framework OpenGL -framework AppKit
	
%.o : %.c
	$(CC) $(CFAGS) -c $< -o $@
	
clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf ${NAME}

re : fclean all

.PHONY: all clean fclean re