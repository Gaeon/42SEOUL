#ifndef PHILO_H
# define PHILO_H

# include "string.h"	// memset
# include "stdio.h"		// printf
# include "stdlib.h"	// malloc free
# include "unistd.h"	// write usleep
# include "sys/time.h"	// gettimeofday
# include "pthread.h"	// pthread_create pthread_detach pthread_join 
						// pthread_mutex_init pthread_mutex_destroy 
						// pthread_mutex_lock pthread_mutex_unlock

# define EAT 			0
# define SLEEP 			1
# define FORK		 	2
# define THINK			3
# define DIED 			4
# define OVER 			5

# define WHI  "\033[0m"
# define PEO  "\033[0;35m" 
# define RED  "\033[0;31m"
# define CYAN "\033[0;36m"
# define BLUE "\033[0;34m"
# define YEL "\033[0;33m"

typedef struct	s_philo
{
	pthread_t		id;
	int				num;
	int				left_fork;
	int				right_fork;
	int				is_eating;
	int				eat_cnt;
	long long		time;
	struct s_info	*info;
}	t_philo;

typedef struct	s_info
{
	t_philo			*philos;
	pthread_mutex_t	*fork;
	pthread_mutex_t	write_t;
	pthread_mutex_t	dead_t;

	int				n_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				n_eat;
	long long		start;
}	t_info;

//ft_aciton
void	message(t_philo *p, int a, int b);
void	*monitor(void *p);
void	hold_fork(t_philo *p);
void	eat(t_philo *p);
void	put_fork(t_philo *p);

//ft_init
void init_info(t_info *info);
void init_philo(t_info *info);

//ft_util
int			ft_atoi(const char *str);
int			ft_error(t_info *info, char *str);
long long	get_time(void);
void		ft_sleep(long long time);

#endif