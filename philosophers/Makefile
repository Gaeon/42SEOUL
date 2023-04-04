CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = philo

HEADER  = ./philo.h

SRCS = 	./philo.c		\
		./ft_setting.c 	\
		./ft_action.c 	\
		./ft_util.c 

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
