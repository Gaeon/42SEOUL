#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int ft_putstr(char *str)
{
	int	res;
	int	idx;

	res = 0;
	idx = 0;
	if (!str)
		res += ft_putstr("(null)");
	else
	{
		while (str[idx])
		{
			res += ft_putchar(str[idx]);
			idx++;
		}
	}
	return (res);
}

int ft_putnbr(int num)
{
	int res;

	res = 0;
	if (num == -2147483648)
		return (ft_putstr("-2147483648"));
	if (num < 0)
	{
		res += ft_putchar('-');
		num *= -1;
	}
	if (num < 10)
		res += ft_putchar(num + '0');
	else
	{
		res += ft_putnbr(num / 10);
		res += ft_putnbr(num % 10);
	}
	return (res);
}

int ft_putnbr_hex(unsigned int nbr)
{
	int res;

	res = 0;
	if (nbr < 16)
		res += write(1, &"0123456789abcdef"[nbr], 1);
	else
	{
		res += ft_putnbr_hex(nbr / 10);
		res += ft_putnbr_hex(nbr % 10);
	}
	return (res);
}

int	ft_printf_type(va_list ap, char c)
{
	int res;

	res = 0;
	if (c == 'c')
		res += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		res += ft_putstr(va_arg(ap, char *));
	else if (c == 'd')
		res += ft_putnbr(va_arg(ap, int));
	else if (c == 'x')
		res += ft_putnbr_hex(va_arg(ap, unsigned int));
	else if (c == '%')
		res += write(1, "%", 1);
	return (res);
}

int	ft_printf(const char *str, ...)
{
	int	res;
	int	idx;
	va_list ap;

	res = 0;
	idx = 0;
	va_start(ap, str);
	while (str[idx])
	{
		if (str[idx] == '%')
			res += ft_printf_type(ap, str[++idx]);
		else
			res += ft_putchar(str[idx]);
		idx++;
	}
	va_end(ap);
	return (res);
}

int main(void)
{
	int num = 100;
	char *str = "abadfwa";
	char c = 'k';
	ft_printf("%d\n", num);
	ft_printf("%s\n", str);
	ft_printf("%c\n", c);
	ft_printf("%%");
	ft_printf("   ab %s %d", str, num);
	return (0);
}
