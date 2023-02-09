/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putall_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:50:31 by tnantaki          #+#    #+#             */
/*   Updated: 2023/02/09 10:50:34 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_putchar_n(char c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, &c, 1);
		i++;
	}
	return (n);
}

int	ft_putstr_n(char *s, int len_nb)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (i < len_nb)
		write(1, &s[i++], 1);
	return (i);
}

t_flag	ft_putnbr(long long n, t_flag pts)
{
	int		i;
	char	nbr[12];

	i = 0;
	pts.negative = 0;
	if (n < 0)
	{
		n *= -1;
		pts.negative = 1;
	}
	if (n == 0 && !pts.dot)
		nbr[i++] = '0';
	while (n > 0)
	{
		nbr[i++] = (n % 10) + '0';
		n /= 10;
	}
	nbr[i] = '\0';
	ft_reverse(nbr);
	pts = ft_write_nb(nbr, pts);
	return (pts);
}

t_flag	ft_put16(unsigned long long n, char k, t_flag pts)
{
	int		i;
	char	nbr[20];

	i = 0;
	if (k == 'x' || k == 'X')
		n = (unsigned int)n;
	if (n == 0 && !pts.dot)
		nbr[i++] = '0';
	while (n > 0)
	{
		if (k == 'x' || k == 'p')
			nbr[i++] = "0123456789abcdef"[n % 16];
		else
			nbr[i++] = "0123456789ABCDEF"[n % 16];
		n /= 16;
	}
	nbr[i] = '\0';
	ft_reverse(nbr);
	pts = ft_write_nb16(nbr, pts, k);
	return (pts);
}
