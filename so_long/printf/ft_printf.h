#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

//ft_printf.c
int		ft_format(char c, va_list ap);
int		ft_printf(const char *str, ...);
int		ft_print_c(int c);
int		ft_print_s(char *str);
int		ft_print_di(int nbr);

//ft_printf_util.c
size_t	ft_strlen(const char *s);
int		ft_putnbr(int nb);

#endif