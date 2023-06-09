/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 21:05:55 by gaeon             #+#    #+#             */
/*   Updated: 2023/06/09 21:05:56 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

void	ft_create_semaphores(t_simul *simul)
{
	sem_unlink("death");
	sem_unlink("message");
	sem_unlink("stop");
	sem_unlink("forks");
	simul->death = sem_open("death", O_CREAT, 0600, 1);
	simul->message = sem_open("message", O_CREAT, 0600, 1);
	simul->stop = sem_open("stop", O_CREAT, 0600, 1);
	simul->forks = sem_open("forks", O_CREAT, 0600,
			simul->philo_numbers);
}

void	ft_destroy_all(t_simul *simul, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < simul->philo_numbers)
		kill(philo[i++].pid, SIGKILL);
	sem_close(simul->death);
	sem_close(simul->message);
	sem_close(simul->stop);
	sem_close(simul->forks);
	free(philo);
}

t_philo	*ft_philo_init(t_simul *simul)
{
	t_philo	*philo;
	int		i;

	i = -1;
	philo = malloc(sizeof(t_philo) * simul->philo_numbers);
	simul->death = NULL;
	simul->stop = NULL;
	simul->message = NULL;
	simul->forks = NULL;
	while (++i < simul->philo_numbers)
		ft_for_each_philo(simul, philo, i);
	return (philo);
}

void	ft_for_each_philo(t_simul *simul, t_philo *philo, int i)
{
	philo[i].index = i;
	philo[i].is_dead = NO;
	philo[i].data = simul;
	philo[i].pid = -1;
	if (simul->eat_counter == -1)
		philo[i].eat_counter = -1;
	else
		philo[i].eat_counter = simul->eat_counter;
}
