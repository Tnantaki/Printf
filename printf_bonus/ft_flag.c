/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:15:08 by tnantaki          #+#    #+#             */
/*   Updated: 2022/10/16 10:16:33 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	ft_checkflag1(char *fmt, t_flag pts)
{
	size_t	i;

	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '+' && pts.plus == 0)
			pts.plus = 1;
		else if (fmt[i] == ' ' && pts.space == 0)
			pts.space = 1;
		else if (fmt[i] == '#' && pts.hash == 0)
			pts.hash = 1;
		i++;
	}
	return (pts);
}

t_flag	ft_checkflag2(char *fmt, t_flag pts)
{
	int	i;

	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '-' && pts.minus == 0)
			pts.minus = 1;
		else if (fmt[i] == '0' && pts.zero == 0 && pts.wid == 0)
			pts.zero = 1;
		else if (ft_isdigit(fmt[i]) && pts.pis == 0 && pts.wid == 0)
			pts.wid = ft_atoi(fmt);
		else if (fmt[i] == '.')
		{
			pts.dot = 1;
			pts.pis = ft_atoi(fmt + i + 1);
			if (fmt[ft_strlen(fmt) - 1] != 's')
				pts.zero = 0;
		}
		i++;
	}
	return (pts);
}

t_flag	ft_flag(char *fmt, t_flag pts)
{
	pts.len_nb = 0;
	pts.len_sign = 0;
	pts.plus = 0;
	pts.minus = 0;
	pts.space = 0;
	pts.hash = 0;
	pts.zero = 0;
	pts.wid = 0;
	pts.pis = 0;
	pts.dot = 0;
	pts = ft_checkflag1(fmt, pts);
	pts = ft_checkflag2(fmt, pts);
	return (pts);
}
