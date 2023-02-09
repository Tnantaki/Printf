/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:29:29 by tnantaki          #+#    #+#             */
/*   Updated: 2022/10/17 14:55:21 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>// For Checking, Don't forget to delete.

static int	ft_putstr(char *s)
{
	int	len;

	if (!s)
		s = "(null)";
	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
	return (len);
}

static int	ft_putnbr(long long n)
{
	int		i;
	int		len;
	char	nbr[12];

	i = 0;
	len = 0;
	if (n == 0)
		return (write(1, "0", 1));
	else if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (n < 0)
	{
		len = write(1, "-", 1);
		n *= -1;
	}
	while (n > 0)
	{
		nbr[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (--i >= 0)
		len += write(1, &nbr[i], 1);
	return (len);
}

static int	ft_put16(unsigned long long n, char k)
{
	int		i;
	int		len;
	char	nbr[20];

	i = 0;
	len = 0;
	if (k == 'x' || k == 'X')
		n = (unsigned int)n;
	if (n == 0)
		nbr[i++] = '0';
	while (n > 0)
	{
		if (k == 'x' || k == 'p')
			nbr[i++] = "0123456789abcdef"[n % 16];
		else
			nbr[i++] = "0123456789ABCDEF"[n % 16];
		n /= 16;
	}
	if (k == 'p')
		len += write(1, "0x", 2);
	while (i > 0)
		len += write(1, &nbr[--i], 1);
	return (len);
}

static int	ft_checktype(char c, va_list pra)
{
	int	len;

	len = 0;
	if (c == 'c')
	{
		c = va_arg(pra, int);
		len += write(1, &c, 1);
	}
	else if (c == 's')
		len += ft_putstr(va_arg(pra, char *));
	else if (c == 'p' || c == 'x' || c == 'X')
		len += ft_put16(va_arg(pra, unsigned long long), c);
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(pra, int));
	else if (c == 'u')
		len += ft_putnbr(va_arg(pra, unsigned int));
	else if (c == '%')
		len += write(1, "%%", 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	pra;

	i = 0;
	len = 0;
	va_start(pra, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			len += ft_checktype(str[++i], pra);
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(pra);
	return (len);
}

// int	main(void)
// {
// 	// char c  = 'A';
// 	int lenprintf;
// 	int ft_lenprintf;
// 	char *str = "Hello";
// 	// long nb = INT_MIN + (-1000000000000);
// 	// int		n = nb;
// 	// int b = INT_MIN + (-1000000000000);
// 	// ft_lenprintf intintf("%x\n", LONG_MAX);
// 	// lenprintf = printf("%X\n", LONG_MAX);
// 	// ft_lenprintf = ft_printf("%X\n", LONG_MAX);
// 	lenprintf = printf("%s\n", str);
// 	ft_lenprintf = ft_printf("%s\n", str);
// 	printf("lenprint   :%d\n", lenprintf);
// 	printf("ft_lenprint:%d\n", ft_lenprintf);
// 	// printf("%d\n", nb);
// 	// printf("%u\n", nb + 1000000000);
// 	// printf("%d\n", INT_MIN - 20);
// 	// ft_printf("%d\n", INT_MIN - 20);
// 	// printf("%p\n", str);
// }
