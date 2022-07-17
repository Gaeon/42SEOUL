/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 13:58:55 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/17 16:38:54 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_word_cnt(char const *s, char c)
{
	int	idx;
	int	cnt;

	idx = 0;
	cnt = 0;
	while (s[idx])
	{
		if (s[idx] != c && (s[idx + 1] == c || s[idx + 1] == '\0'))
			cnt++;
		idx++;
	}
	return (cnt);
}

void	ft_strcpy(char *array, const char *s, int word_len)
{
	int	i;

	i = 0;
	while (i < word_len)
	{
		array[i] = s[i];
		i++;
	}
	array[i] = '\0';
}

void	ft_make(const char *s, char c, char **array)
{
	int	i;
	int	k;
	int	word_len;

	i = 0;
	k = 0;
	while (s[i] != 0)
	{
		word_len = 0;
		while (s[i + word_len] != c)
			word_len++;
		if (word_len > 0)
		{
			array[k] = (char *)malloc(sizeof(char) * (word_len + 1));
			if (array[k] == 0)
				return ;
			ft_strcpy(array[k], &s[i], word_len);
			k++;
		}
		i += word_len + 1;
	}
	array[k] = 0;
}

char	**ft_split(char const *s, char c)
{
	int		cnt;
	char	**array;

	if (s == 0)
		return (0);
	cnt = ft_word_cnt(s, c);
	array = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (array == 0)
		return (0);
	ft_make(s, c, array);
	return (array);
}
