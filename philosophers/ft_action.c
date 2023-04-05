#include "philo.h"

void	*monitor(void *p)
{
	t_philo			*philo;

	philo = (t_philo *)p;
	while (1)
	{
		if (!philo->is_eating && \
				get_time() - philo->time > philo->info->t_die)
		{
			message(philo, DIED, 0);
			pthread_mutex_unlock(&philo->info->dead_t);	//?????
			return ((void *) 0);
		}
		usleep(1000);
	}
	return ((void *) 1);
}


void	hold_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->fork[philo->left_fork]);
	message(philo, FORK, 1);
	pthread_mutex_lock(&philo->info->fork[philo->right_fork]);
	message(philo, FORK, 1);
}

void	eat(t_philo *philo)
{
	philo->is_eating = 1;
	message(philo, EAT, 1);
	philo->eat_cnt++;
	philo->time = get_time();
	ft_sleep(philo->info->t_eat);
	philo->is_eating = 0;
}

void	put_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->info->fork[philo->left_fork]);
	pthread_mutex_unlock(&philo->info->fork[philo->right_fork]);
	message(philo, SLEEP, 1);
	ft_sleep(philo->info->t_eat);
	message(philo, THINK, 1);
}

void	ft_sleep(long long time)
{
	long long	t;

	t = get_time();
	while (1)
	{
		if (get_time() - t >= time)
			break ;
		usleep(300);
	}
}
