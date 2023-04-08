# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/06 19:31:18 by gaeokim           #+#    #+#              #
#    Updated: 2023/04/08 17:58:03 by gaeokim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = cc
CFLAGS = -Wall -Wextra -Werror 
#-g -fsanitize=thread

NAME = philo

HEADER = ./philo.h

SRC =	./philo.c 		\
		./ft_setting.c	\
		./ft_action.c	\
		./ft_util.c
OBJS = $(SRC:.c=.o)
	
all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@
	
%.o : %.c
	@$(CC) $(CFAGS) -c $< -o $@

	
clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
