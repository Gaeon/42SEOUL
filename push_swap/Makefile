# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 13:36:31 by marvin            #+#    #+#              #
#    Updated: 2023/02/23 17:32:17 by gaeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

HEADER  = ./push_swap.h

SRCS = 	./push_swap.c 					\
		./util.c						\
		./parsing/setting.c 			\
		./parsing/util_atoi.c 			\
		./parsing/util_split.c 			\
		./algorithm/sorting.c 			\
		./algorithm/util.c 				\
		./operation/operation_sx.c 		\
		./operation/operation_px.c 		\
		./operation/operation_rx.c 		\
		./operation/operation_rrx.c 	\
		./ft_printf/ft_printf.c			\
		./ft_printf/ft_printf_util.c 	\
		./ft_printf/ft_printf_format.c
		
		
OBJS = $(SRCS:.c=.o)

all : $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean :
	rm -f $(OBJS)

fclean :	clean
	rm -f $(NAME)

re :	fclean all

.PHONY : all clean fclean re
