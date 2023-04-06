/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:10:58 by gaeokim           #+#    #+#             */
/*   Updated: 2023/04/06 17:42:17 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

int	ft_atoi(const char *str)
{
	int		idx;
	long	ret;

	idx = 0;
	ret = 0;
	while ((9 <= str[idx] && str[idx] <= 13) || str[idx] == 32)
		idx++;
	if (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			ft_error(0, "Error: THE ARGUMENT MUST BE POSITIVE\n");
		idx++;
	}
	while (str[idx])
	{
		if ('0' <= str[idx] && str[idx] <= '9')
			ret = ret * 10 + str[idx] - '0';
		else
			ft_error(0, "Error: THE ARGUMENT MUST BE A NUMBER\n");
		if (ret > 2147483647)
			ft_error(0, "Error: THE ARGUMENT MUST BE IN THE RANGE OF INT\n");
		idx++;
	}
	return ((int)ret);
}

int	ft_error(t_info *info, char *str)
{
	int	i;

	i = -1;
	if (info)
	{
		pthread_mutex_destroy(&info->dead_t);
		pthread_mutex_destroy(&info->message_t);
		while (++i < info->n_philos)
			pthread_mutex_destroy(&info->fork[i]);
		free(info->fork);
		free(info);
	}
	if (str)
		printf("%s%s", RED, str);
	exit(1);
}

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	message(t_philo *philo, int status, int unlock)
{
	pthread_mutex_lock(&philo->info->message_t);
	printf("%s%lld %d ", WHI, get_time() - philo->info->start, philo->num);
	if (status == EAT)
		printf("%sis eating\n", CYAN);
	if (status == SLEEP)
		printf("%sis sleeping\n", PEO);
	if (status == FORK)
		printf("%shas taken a fork\n", BLUE);
	if (status == THINK)
		printf("%sis thinking\n", YEL);
	if (status == DIED)
		printf("%sdied\n", RED);
	if (status == OVER)
		printf("%smust eat count reached\n", RED);
	if (unlock)
		pthread_mutex_unlock(&philo->info->message_t);
}
