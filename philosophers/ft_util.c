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
			return (-1);
		idx++;
	}
	while (str[idx])
	{
		if ('0' <= str[idx] && str[idx] <= '9')
			ret = ret * 10 + str[idx] - '0';
		else
			ft_error(0, "Error: THE ARGUMENT MUST BE A NUMBER\n");
		if (ret > 2147483647)
				return (-1);
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
		pthread_mutex_destroy(&info->write_t);
		while(++i < info->n_philos)
			pthread_mutex_destroy(&info->fork[i]);
		free(info->fork);
		free(info);
	}
	if(str)
		printf("%s", str);
	exit(1);
}

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
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

