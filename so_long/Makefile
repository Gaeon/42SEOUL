# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 19:31:58 by gaeokim           #+#    #+#              #
#    Updated: 2023/01/16 15:45:21 by gaeokim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

SRC =	./so_long.c					\
		./so_long_init.c			\
		./so_long_map.c				\
		./so_long_util.c			\
		./so_long_root_check.c 		\
		./so_long_move.c			\
		./so_long_window.c 			\
		printf/ft_printf.c			\
		printf/ft_printf_util.c		\
		gnl/get_next_line.c			\
		gnl/get_next_line_util.c
OBJS = $(SRC:.c=.o)
NAME = so_long

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} -Lmlx -lmlx -framework OpenGL -framework AppKit
	
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf ${NAME}

re : fclean all

.PHONY: all clean fclean re