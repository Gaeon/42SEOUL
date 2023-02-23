void	btoa_util(t_stack *init, t_count *cnt, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (init->b[init->size_b] <= init->pivot2)
		{
			rb(init, 1);
			cnt->rb += 1;
		}
		else
		{
			pa(init);
			cnt->pa += 1;
			if (init->a[init->size_a] <= init->pivot1)
			{
				ra(init, 1);
				cnt->ra += 1;
			}
		}
		i++;
	}
}

void	atob_util(t_stack *init, t_count *cnt, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (init->a[init->size_a] >= init->pivot1)
		{
			ra(init, 1);
			cnt->ra += 1;
		}
		else
		{
			pb(init);
			cnt->pb += 1;
			if (init->b[init->size_b] >= init->pivot2)
			{
				rb(init, 1);
				cnt->rb += 1;
			}
		}
		i++;
	}
}

void	atob(t_stack *init, int size)
{
	t_count		cnt;
	int			idx;

	cnt = (t_count){0, 0, 0, 0};
	if (check_a_sort(init, size))
		return ;
	if (size <= 3)
	{
		size_a(init, size);
		return ;
	}
	get_pivot(init, size, 1);
	atob_util(init, &cnt, size);
	idx = -1;
	while (++idx < cnt.ra)
		rrr(init);
	atob(init, cnt.ra);
	btoa(init, cnt.rb);
	btoa(init, cnt.pb - cnt.rb);
}

void	btoa(t_stack *init, int size)
{
	t_count		cnt;
	int			idx;

	cnt = (t_count){0, 0, 0, 0};
	if (check_b_sort(init, size))
	{
		while (size--)
			pa(init);
		return ;
	}
	if (size <= 3)
	{
		size_b(init, size);
		return ;
	}
	get_pivot(init, size, 0);
	btoa_util(init, &cnt, size);
	atob(init, cnt.pa - cnt.ra);
	idx = -1;
	while (++idx < cnt.ra)
		rrr(init);
	atob(init, cnt.rb);
	btoa(init, cnt.ra);
}