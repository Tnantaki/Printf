/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:03:05 by tnantaki          #+#    #+#             */
/*   Updated: 2022/10/12 11:05:04 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

# include <stdio.h>

int	ft_printf(const char *str, ...);
int	ft_checktype(char c, va_list pra);
int	ft_putstr(char *s);
int	ft_putnbr(long long n);
int	ft_put16(unsigned long long n, char k);

#endif
