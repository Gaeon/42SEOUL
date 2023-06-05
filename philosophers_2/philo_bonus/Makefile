# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 13:53:11 by gaeon             #+#    #+#              #
#    Updated: 2023/06/05 14:04:33 by gaeon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	philo_bonus
CC					=	gcc
CFLAGS				=	-Wall -Werror -Wextra
# CFLAGS += -g
# CFLAGS += -fsanitize=address
RM					=	rm
RMFLAGS				=	-rf

SRCS	=	philo.c			\	
			ft_action.c		\
			ft_parse.c		\
			ft_setting.c	\
			ft_util.c
			
OBJS	=	$(SRCS:.c=.o)

all 	: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@
	
%.o 	: %.c
	@$(CC) $(CFAGS) -c $< -o $@

	
clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re