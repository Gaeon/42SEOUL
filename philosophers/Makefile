CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = philo

HEADER  = ./philo.h

SRCS = 	./philo.c		\
		./init.c 		\
		./util.c 		\
		./action.c

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
