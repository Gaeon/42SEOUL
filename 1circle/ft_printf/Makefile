# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/05 19:10:56 by gaeokim           #+#    #+#              #
#    Updated: 2022/07/21 16:42:40 by gaeokim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

HEADER  = ./ft_printf.h

SRCS = 	./ft_printf.c
OBJS = $(SRCS:.c=.o)

SRCS_BONUS =
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

ifdef BONUS
	OBJS_F = $(OBJS) $(OBJS_BONUS)
else
	OBJS_F = $(OBJS)
endif

all : $(NAME)

.c.o :
	$(CC) $(CFLAG) -c $< -o $@

$(NAME) : $(OBJS_F)
	ar rc $(NAME) $(OBJS_F)

bonus :
	make BONUS=1 all

clean :
	rm -f $(OBJS) $(OBJS_BONUS)

fclean :	clean
	rm -f $(NAME)

re :	fclean all

.PHONY : all bonus clean fclean re
