#ifndef PHILO_H
# define PHILO_H

# include "string.h"	//memset
# include "stdio.h"		//printf
# include "stdlib.h"	//malloc free
# include "unistd.h"	//write usleep
# include "sys/time.h"	//gettimeofday
# include "pthread.h"	//  pthread_create pthread_detach pthread_join 
						// pthread_mutex_init pthread_mutex_destroy 
						//pthread_mutex_lock pthread_mutex_unlock

typedef struct s_info{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
}	t_info;

#endif