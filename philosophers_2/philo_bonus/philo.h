/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 21:06:07 by gaeon             #+#    #+#             */
/*   Updated: 2023/06/09 21:06:08 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <semaphore.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <signal.h>

# define YES 1
# define NO 0
# define FORK 1
# define EATING 2
# define SLEEPING 3
# define THINKING 4
# define DIED 5
# define DONE 6

typedef struct s_simul
{
	sem_t			*forks;
	sem_t			*message;
	sem_t			*death;
	sem_t			*stop;
	unsigned int	start;
	int				philo_numbers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_counter;
	int				max_eat;
	int				current_eat;
}				t_simul;

typedef struct s_philo
{
	t_simul	*data;
	pid_t			pid;
	unsigned int	eating_time;
	unsigned int	next_meal;
	int				index;
	int				is_dead;
	int				eat_counter;
}				t_philo;

// ft_action.c
void			ft_take_fork(t_philo *philo);
void			ft_eat(t_philo *philo);
void			ft_sleep(t_philo *philo);

// ft_parse.c
int				ft_set_rest(t_simul *simul, int num, int i);
int				ft_error_put(t_simul *simul, char *message, int ret);
int				ft_set_data(t_simul *simul, int num, int i);
int				ft_get_number(char *arg);
int				ft_parsing(char **argv, t_simul *simul);

// ft_setting.c
void			ft_create_semaphores(t_simul *simul);
void			ft_destroy_all(t_simul *simul, t_philo *philo);
t_philo			*ft_philo_init(t_simul *simul);
void			ft_for_each_philo(t_simul *simul, t_philo *philo, int i);
					
// ft_utils.c
unsigned int	ft_get_time(void);
void			ft_print_message(int id, t_philo *philo);

// philo.c
void			*ft_check_death(void *arg);
void			ft_routine(t_philo *philo);




#endif