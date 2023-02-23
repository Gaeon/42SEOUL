#include "../push_swap.h"

int is_stack_sorted(t_info *info, int flag)
{
    int idx;

    idx = 0;
	while (flag == 1 && idx < info->a->size)
	{
		if (info->a->arr[idx] > info->a->arr[idx + 1])
			return (0);
		idx++;
	}
    while (flag == 2 && idx < info->b->size)
    {
        if (info->b->arr[idx] > info->b->arr[idx + 1])
			return (0);
		idx++;
    }
	return (1);
}

void    sort_duplicate_stack(int *array, int size)
{
    int i;
	int	j;
	int	temp;

    i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int *duplicate_stack(t_info *info, int flag)
{
    int idx;
    int *array;

    idx = 0;
    array = (int *)malloc(sizeof(int) * (info->size));
    while (flag == 1 && idx < info->size)
    {
        array[idx] = info->a->arr[idx];
        idx++;
    }
    while (flag == 2 && idx < info->size)
    {
        array[idx] = info->a->arr[idx];
        idx++;
    }
    return (array);
}
