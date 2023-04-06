/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:10:34 by gaeokim           #+#    #+#             */
/*   Updated: 2023/04/06 19:47:32 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdlib.h>

void	*die_check(void *phi)
{
	t_info			*info;
	int				i;

	info = (t_info *)phi;
	while (1)
	{
		i = 0;
		while (i < info->n_philos)
		{
			if (info->philos[i].eat_cnt >= info->n_eat)
				i++;
			else
				break ;
		}
		if (i == info->n_philos)
		{
			message(&info->philos[0], OVER, 0);
			pthread_mutex_unlock(&info->dead_t);
			break ;
		}
		usleep(100);
	}
	return (0);
}

void	*func(void *t)
{
	t_philo		*philo;
	pthread_t	id;

	philo = (t_philo *)t;
	philo->time = philo->info->start;
	pthread_create(&id, NULL, &monitor, philo);
	pthread_detach(id);
	while (1)
	{
		hold_fork(philo);
		eat(philo);
		put_fork(philo);
	}
	return (NULL);
}

void	start(t_info *info)
{
	int			i;
	pthread_t	id;

	i = -1;
	info->start = get_time();
	if (info->n_eat)
	{
		pthread_create(&id, 0, die_check, (void *)info);
		pthread_detach(id);
	}
	while (++i < info->n_philos)
	{
		if (pthread_create(&info->philos[i].id, 0, \
			func, (void *)(&info->philos[i])))
			ft_error(info, "Thread Create Error!\n");
		pthread_detach(info->philos[i].id);
		usleep(100);
	}
}

void	init_mutex(t_info *info)
{
	int	i;

	i = -1;
	pthread_mutex_init(&info->message_t, 0);
	pthread_mutex_init(&info->dead_t, 0);
	pthread_mutex_lock(&info->dead_t);
	info->fork = malloc(sizeof(pthread_mutex_t) * info->n_philos);
	if (!info->fork)
		ft_error(0, "Memory Allocation Error!\n");
	while (++i < info->n_philos)
		pthread_mutex_init(&info->fork[i], 0);
}

void	init(t_info *info)
{
	int	i;

	i = -1;
	info->fork = 0;
	info->philos = malloc(sizeof(t_philo) * info->n_philos);
	if (!info->philos)
		ft_error(0, "Memory Allocation Error!\n");
	while (++i < info->n_philos)
	{
		info->philos[i].num = i + 1;
		info->philos[i].is_eating = 0;
		info->philos[i].left_fork = i;
		info->philos[i].right_fork = (i + 1) % info->n_philos;
		info->philos[i].eat_cnt = 0;
		info->philos[i].info = info;
	}
	init_mutex(info);
}
