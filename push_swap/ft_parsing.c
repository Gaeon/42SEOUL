/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:49:30 by gaeokim           #+#    #+#             */
/*   Updated: 2023/02/01 18:12:18 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_error(int *array)
{
	free(array);
	write(1, "Error\n", 7);
	exit(1);
}

long	ft_atoi(const char *str)
{
	int		idx;
	int		sign;
	long	ret;

	idx = 0;
	sign = 1;
	ret = 0;
	while ((9 <= str[idx] && str[idx] <= 13) || str[idx] == 32)
		idx++;
	if (str[idx] == '+' || str[idx] == '-')
	{
		if (str[idx] == '-')
			sign = -1;
		idx++;
	}
	while ('0' <= str[idx] && str[idx] <= '9')
	{
		ret = ret * 10 + str[idx] - '0';
		if (sign == 1 && ret > 2147483647 || sign == -1 && ret > 2147483648)
			return (2147483648);
		idx++;
	}
	return (sign * ret);
}

int	ft_word_cnt(char const *s)
{
	int	idx;
	int	cnt;

	idx = 0;
	cnt = 0;
	while (s[idx])
	{
		if (s[idx] != ' ' && (s[idx + 1] == ' ' || s[idx + 1] == '\0'))
			cnt++;
		idx++;
	}
	return (cnt);
}

void	ft_make(char const *s, int *array)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	word_len;
	long			tmp;

	i = 0;
	k = 0;
	while (i < ft_strlen(s))
	{
		word_len = 0;
		while (s[i + word_len] && s[i + word_len] != ' ')
			word_len++;
		if (word_len > 0)
		{
			tmp = ft_atoi(&s[i]);
			if (tmp == 2147483648)
				ft_free_error(array);
			array[k] = (int)tmp;
			k++;
		}
		i += word_len + 1;
	}
}

int	*ft_split(char const *s)
{
	int		idx;
	int		*array;

	idx = 0;
	if (s == 0)
		return (0);
	while (s[idx] != '\0')
	{
		if (s[idx] < '0' && s[idx] > '9' || s[idx] != ' '
			|| s[idx] != '+' || s[idx] != '-')
			ft_error();
		idx++;
	}
	array = (int *)malloc(sizeof(char *) * (ft_word_cnt(s) + 1));
	if (array == 0)
		return (0);
	ft_make(s, array);
	return (array);
}
