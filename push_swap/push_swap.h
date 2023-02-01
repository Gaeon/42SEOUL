/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:21:19 by marvin            #+#    #+#             */
/*   Updated: 2023/02/01 18:49:54 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_node{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_info{
	int		size_a;
	int		size_b;
	t_node	*top_a;
	t_node	*bottom_a;
	t_node	*top_b;
	t_node	*bottom_b;
}	t_info;

//ft_printf.c
int		ft_input_check(const char *str);
int		ft_format(char c, va_list ap);
int		ft_printf(const char *str, ...);

//operation.c
void	sa(t_info *info);
void	sb(t_info *info);
void	ss(t_info *info);

void	pa(t_info *info);
void	pb(t_info *info);

void	ra(t_info *info);
void	rb(t_info *info);
void	rr(t_info *info);

void	rra(t_info *info);
void	rrb(t_info *info);
void	rrr(t_info *info);

//list_function
void	ft_lstadd_back_a(t_node *new, t_info *info);
void	ft_lstadd_back_b(t_node *new, t_info *info);
void	ft_lstclear_a(t_info *info, void (*del)(void *));
void	ft_lstdelone(t_node *lst);
t_node	*ft_lstnew(int data);

//ft_parsing.c
void	ft_free_error(int *array);
long	ft_atoi(const char *str);
int		ft_word_cnt(char const *s);
void	ft_make(char const *s, int *array);
int		*ft_split(char const *s);

//util.c
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

//push_swap.c
void	ft_error(int errno);
int		ft_parsing(char *argv, t_node *node, t_info *info);

#endif
