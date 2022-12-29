# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/28 19:31:58 by gaeokim           #+#    #+#              #
#    Updated: 2022/12/28 20:38:43 by gaeokim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = so_long

HEADER  = ./so_long.h

SRCS = 	./so_long.c
OBJS = $(SRCS:.c=.o)

MLX = mlx
MLX_DIR = ./minilibx_opengl_20191021

$(NAME) : $(OBJS)
	$(MAKE) -C $(MLX_DIR) all
	$(CC) $(CFLAGS) -L$(MLX_DIR) -l $(MLX) -framework OpenGL -framework AppKit $< -o $@

.c.o :
	$(CC) $(CFLAGS) -I$(MLX_DIR) -c $< -o $@
	
all : $(NAME)

clean :
	rm -f $(OBJS)

fclean :	clean
	rm -f $(NAME)

re :	fclean all

.PHONY : all clean fclean re
