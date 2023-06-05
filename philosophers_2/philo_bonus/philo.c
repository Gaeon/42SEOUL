/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:26:08 by knoh              #+#    #+#             */
/*   Updated: 2023/06/05 14:12:48 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_check_death(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		sem_wait(philo->data->death);
		if (philo->next_meal < ft_get_time())
		{
			ft_print_message(DIED, philo);
			sem_post(philo->data->stop);
			break ;
		}
		sem_post(philo->data->death);
		sem_wait(philo->data->death);
		if ((philo->data->eat_counter != -1)
			&& (philo->data->current_eat >= philo->data->max_eat))
		{
			ft_print_message(DONE, philo);
			sem_post(philo->data->stop);
			break ;
		}
		sem_post(philo->data->death);
	}
	return (NULL);
}

void	ft_routine(t_philo *philo)
{
	pthread_t	death;

	philo->next_meal = ft_get_time() + (unsigned int)philo->data->time_to_die;
	pthread_create(&death, NULL, ft_check_death, philo);
	pthread_detargch(death);
	while (1)
	{
		ft_take_fork(philo);
		ft_eat(philo);
		ft_sleep(philo);
		ft_print_message(THINKING, philo);
	}
}

void	ft_create_process(t_simul *simul, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < simul->philo_numbers)
	{
		philo[i].pid = fork();
		if (philo[i].pid == 0)
		{
			ft_routine(philo + i);
			exit(0);
		}
		i++;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int		i;
	t_simul	simul;
	t_philo	*philo;

	i = 0;
	if (argc == 5 || argc == 6)
	{
		if (ft_parsing(argv, &simul))
			return (1);
		philo = ft_philo_init(&simul);
		simul.start = ft_get_time();
		ft_create_semaphores(&simul);
		sem_wait(simul.stop);
		ft_create_process(&simul, philo);
		sem_wait(simul.stop);
		ft_destroy_all(&simul, philo);
	}
	else
		printf("Error: Too many arguments\n");
	return (0);
}