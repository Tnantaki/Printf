/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:49:58 by tnantaki          #+#    #+#             */
/*   Updated: 2023/02/09 10:50:01 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static t_flag	ft_checktype(va_list pra, t_flag pts, char c)
{
	if (c == 'c')
		pts = ft_write_char(va_arg(pra, int), pts);
	else if (c == 's')
		pts = ft_write_str(va_arg(pra, char *), pts);
	else if (c == 'p' || c == 'x' || c == 'X')
		pts = ft_put16(va_arg(pra, unsigned long long), c, pts);
	else if (c == 'd' || c == 'i')
		pts = ft_putnbr(va_arg(pra, int), pts);
	else if (c == 'u')
		pts = ft_putnbr(va_arg(pra, unsigned int), pts);
	return (pts);
}

static int	ft_len_fmt(const char *str)
{
	int		i;
	int		j;
	char	*find;

	i = 0;
	find = "cspxXdiu";
	while (str[i])
	{
		j = 0;
		while (find[j])
		{
			if (find[j] == str[i])
				return (i + 1);
			j++;
		}
		i++;
	}
	return (0);
}

static t_flag	ft_format(va_list pra, const char *str, t_flag pts)
{
	int		len_fmt;
	char	*fmt;

	len_fmt = 0;
	pts.i += 1;
	if (str[pts.i] == '%')
	{
		pts.len_ptf += write(1, "%%", 1);
		return (pts);
	}
	len_fmt = ft_len_fmt(str + pts.i);
	fmt = ft_substr(str, pts.i, len_fmt);
	pts = ft_flag(fmt, pts);
	pts = ft_checktype(pra, pts, fmt[len_fmt - 1]);
	if (fmt != NULL)
		free(fmt);
	pts.i += len_fmt - 1;
	return (pts);
}

int	ft_printf(const char *str, ...)
{
	va_list	pra;
	t_flag	pts;

	pts.i = 0;
	pts.len_ptf = 0;
	va_start(pra, str);
	while (str[pts.i])
	{
		if (str[pts.i] == '%')
			pts = ft_format(pra, str, pts);
		else
			pts.len_ptf += ft_putchar(str[pts.i]);
		pts.i++;
	}
	va_end(pra);
	return (pts.len_ptf);
}
/*
int	main(void)
{
	int lenprintf;
	int ft_lenprintf;
	// char c  = 'A';
	// char *str = ;
	int nb = 100;
	lenprintf = printf("%123s|\n", NULL);
	// ft_lenprintf = ft_printf("%10.7d|\n", nb);
	// printf("lenprint   :%d\n", lenprintf);
	// printf("ft_lenprint:%d\n", ft_lenprintf);
}
*/
