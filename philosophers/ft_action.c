#include "philo.h"

void	message(t_philo *p, int a, int b)
{
	int		ret;

	pthread_mutex_lock(&p->info->write_t);
	printf("%s%lld %d ", WHI, get_time() - p->info->start, p->num);
	if (a == EAT)
		printf("%sis eating\n", CYAN);
	if (a == SLEEP)
		printf("%sis sleeping\n", PEO);
	if (a == FORK)
		printf("%shas taken a fork\n", RED);
	if (a == THINK)
		printf("%sis thinking\n", YEL);
	if (a == DIED)
		printf("%shas died\n", RED);
	if (a == OVER)
		printf("%smust eat count reached\n", RED);
	if (b)
		pthread_mutex_unlock(&p->info->write_t);
}

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
			pthread_mutex_unlock(&philo->info->dead_t);
			return ((void *) 0);
		}
		usleep(1000);
	}
	return ((void *) 1);
}


void	hold_fork(t_philo *p)
{
	pthread_mutex_lock(&p->info->fork[p->left_fork]);
	message(p, FORK, 1);
	pthread_mutex_lock(&p->info->fork[p->right_fork]);
	message(p, FORK, 1);
}

void	eat(t_philo *p)
{
	p->is_eating = 1;
	message(p, EAT, 1);
	p->eat_cnt++;
	p->time = get_time();
	ft_sleep(p->info->t_eat);
	p->is_eating = 0;
}

void	put_fork(t_philo *p)
{
	pthread_mutex_unlock(&p->info->fork[p->left_fork]);
	pthread_mutex_unlock(&p->info->fork[p->right_fork]);
	message(p, SLEEP, 1);
	ft_sleep(p->info->t_eat);
	message(p, THINK, 1);
}