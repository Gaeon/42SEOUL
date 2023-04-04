#include "philo.h"

void	input_check(int	argc, char *argv[])
{
	int	idx;

	idx = 1;
	while(idx < argc)
	{
		if (idx == 1 && ft_atoi(argv[idx]) <= 1)
			ft_error(0, "Error: THE NUMBER OF PHILOSOPHERS CANNOT BE LESS THAN 2\n");
		else if ((2 <= idx && idx <= 4) && ft_atoi(argv[idx]) < 60)
			ft_error(0, "Error: THE time_to_X CAN'T BE LESS THAN 60 ms\n");
		else if (idx == 5 && ft_atoi(argv[idx]) <= 0)
			ft_error(0, "Error: THE NUMBER OF EAT CAN'T BE LESS THAN 1\n");
		idx++;
	}
}

void	setting(char *argv[], t_info *info)
{
	info->n_philos = ft_atoi(argv[1]);
	info->t_die = ft_atoi(argv[2]);
	info->t_eat = ft_atoi(argv[3]);
	info->t_sleep = ft_atoi(argv[4]);
	if (argv[5])
		info->n_eat = ft_atoi(argv[5]);
	else
		info->n_eat = 0;
}

int	main(int argc, char *argv[])
{ 
	t_info	*info;

	if (argc >= 5 && argc <= 6)
	{
		input_check(argc, argv);
		info = (t_info *)malloc(sizeof(t_info));
		setting(argv, info);
		init(info);
		start(info);
		pthread_mutex_lock(&info->dead_t);
		ft_error(info, 0);
	}
	else
		ft_error(0, "Error: THE NUMBER OF ARGUMENTS IS INCORRECT\n");
}
