/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:57:03 by gaeon             #+#    #+#             */
/*   Updated: 2023/06/05 14:09:28 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_take_fork(t_philo *philo)
{
	sem_wait(philo->data->forks);
	ft_print_message(FORK, philo);
	sem_wait(philo->data->forks);
	ft_print_message(FORK, philo);
}

void	ft_eat(t_philo *philo)
{
	ft_print_message(EATING, philo);
	if (philo->data->eat_counter != -1)
		philo->data->current_eat++;
	usleep(philo->data->time_to_eat * 1000);
	philo->eating_time = ft_get_time();
	philo->next_meal = philo->eating_time
		+ (unsigned int)philo->data->time_to_die;
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}

void	ft_sleep(t_philo *philo)
{
	ft_print_message(SLEEPING, philo);
	usleep(philo->data->time_to_sleep * 1000);
}
