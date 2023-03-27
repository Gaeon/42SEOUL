#include "philo.h"

int	input_check(int	argc, char *argv[])
{
	int	idx;

	idx = 1;
	while(idx < argc)
	{
		if (ft_atoi(argv[idx]) < 1)
			return (0);
		idx++;
	}
	return (1);
}

void	setting(char *argv[], t_info *info)
{
	info->n_philos = ft_atoi(argv[1]);
	info->t_die = ft_atoi(argv[2]);
	info->t_eat = ft_atoi(argv[3]);
	info->t_sleep = ft_atoi(argv[4]);
	if (argv[5])
		info->n_eat = ft_atoi(argv[5]);
}

int	main(int argc, char *argv[])
{
	t_info	*info;

	if (argc == 5 || argc == 6)
	{
		if(input_check(argc, argv) == 1)
			return(ft_error(0, "Input Error!\n"));
		info = (t_info *)malloc(sizeof(t_info));
		setting(argv, info);
		init_info(info);
		init_philo(info);
		pthread_mutex_lock(&info->dead_t);
		ft_error(info, 0);
	}
	ft_error(0, "Argument Error!\n");
}
