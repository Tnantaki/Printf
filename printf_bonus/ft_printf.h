/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:40:51 by tnantaki          #+#    #+#             */
/*   Updated: 2022/10/17 09:45:55 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# include <stdio.h>
# include <string.h>
# include <limits.h>

typedef struct t_si
{
	int	len_ptf;
	int	i;
	int	len_nb;
	int	len_sign;
	int	negative;
	int	plus;
	int	minus;
	int	space;
	int	hash;
	int	zero;
	int	wid;
	int	pis;
	int	dot;
}	t_flag;

//mainfunction;
int		ft_printf(const char *str, ...);
//flag
t_flag	ft_flag(char *fmt, t_flag pts);
//utils
size_t	ft_strlen(const char *str);
int		ft_putchar(char c);
int		ft_putstr(char *s);
char	*ft_substr(char const *s, size_t start, size_t len);
void	ft_swap(char *src);
//atoi
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
//putall
int		ft_putchar_n(char c, int n);
int		ft_putstr_n(char *s, int len_nb);
t_flag	ft_putnbr(long long n, t_flag pts);
t_flag	ft_put16(unsigned long long n, char k, t_flag pts);
//write
t_flag	ft_write_char(char c, t_flag pts);
t_flag	ft_write_str(char *s, t_flag pts);
t_flag	ft_write_nb(char *nb, t_flag pts);
t_flag	ft_write_nb16(char *nb, t_flag pts, char k);

#endif
