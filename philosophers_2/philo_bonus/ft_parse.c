/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeon <gaeon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:25:38 by knoh              #+#    #+#             */
/*   Updated: 2023/06/05 14:10:55 by gaeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_set_rest(t_simul *simul, int num, int i)
{
	if (i == 4)
	{
		if (num < 60)
			return (ft_error_put(simul,
					"Error: THE time_to_sleep CAN'T BE LESS THAN 60 ms", 1));
		simul->time_to_sleep = num;
	}
	else if (i == 5)
	{
		if (num == 0)
			simul->eat_counter = -1;
		else
		{
			simul->eat_counter = num;
			simul->current_eat = 0;
			simul->max_eat = num * simul->philo_numbers;
		}
	}
	return (0);
}

int	ft_error_put(t_simul *simul, char *message, int ret)
{
	if (simul)
	{
		if (simul->forks)
			free(simul->forks);
	}
	printf("%s\n", message);
	return (ret);
}

int	ft_set_data(t_simul *simul, int num, int i)
{
	if (i == 1)
	{
		if (num == 0)
			return (ft_error_put(NULL,
					"Error: NO PHELOSOPHER IN THE TABILE", 1));
		simul->philo_numbers = num;
	}
	else if (i == 2)
	{
		if (num < 60)
			return (ft_error_put(simul,
					"Error: THE time_to_die CAN'T BE LESS THAN 60 ms", 1));
		simul->time_to_die = num;
	}
	else if (i == 3)
	{
		if (num < 60)
			return (ft_error_put(simul,
					"Error: THE time_to_eat CAN'T BE LESS THAN 60 ms", 1));
		simul->time_to_eat = num;
	}
	else
		ft_set_rest(simul, num, i);
	return (0);
}

int	ft_get_number(char *arg)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (arg[i])
	{
		if (arg[i] >= '0' && arg[i] <= '9')
			num = num * 10 + (arg[i] - '0');
		else
			return (ft_error_put(NULL, "Error: Number Only", -1));
		i++;
	}
	return (num);
}

int	ft_parsing(char **argv, t_simul *simul)
{
	int				num;
	int				i;

	i = 1;
	while (argv[i])
	{
		num = ft_get_number(argv[i]);
		if (num == -1)
			return (1);
		if (ft_set_data(simul, num, i))
			return (1);
		i++;
	}
	if (i == 5)
	{
		simul->eat_counter = -1;
		simul->current_eat = -1;
		simul->max_eat = -1;
	}
	return (0);
}