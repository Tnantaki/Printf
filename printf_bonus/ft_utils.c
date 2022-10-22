/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 23:02:01 by tnantaki          #+#    #+#             */
/*   Updated: 2022/10/16 12:39:23 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
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

char	*ft_substr(const char *s, size_t start, size_t len)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		dst = (char *)malloc(sizeof(char));
		dst[i] = '\0';
		return (dst);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	while (s[start + i] && i < len)
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

void	ft_swap(char *src)
{
	char	tmp[20];
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(src);
	while (len--)
		tmp[i++] = src[len];
	tmp[i] = '\0';
	i = 0;
	while (tmp[i])
	{
		src[i] = tmp[i];
		i++;
	}
	src[i] = '\0';
}
