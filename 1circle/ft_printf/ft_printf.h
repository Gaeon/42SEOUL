/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaeokim <gaeokim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 16:41:54 by gaeokim           #+#    #+#             */
/*   Updated: 2022/07/22 12:46:32 by gaeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_input_check(const char *str);
ssize_t	ft_format(const char *str, va_list *ap);

char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);
char	*ft_itoa(int n);

ssize_t	ft_print_cs(const char c, va_list *ap);
ssize_t	ft_print_diu(const char c, va_list *ap);
ssize_t	t_print_px(const char c, va_list *ap);
ssize_t	ft_print_X(const char c, va_list *ap);

#endif
