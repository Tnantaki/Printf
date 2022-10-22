/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 23:02:01 by tnantaki          #+#    #+#             */
/*   Updated: 2022/10/13 14:17:17 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	int	nb;
	int	i;

	i = 0;
	nb = 0;
	while (str[i] && !ft_isdigit(str[i]))
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		nb = nb * 10 + (str[i++] - '0');
	}
	return (nb);
}
