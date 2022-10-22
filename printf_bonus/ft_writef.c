/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writef.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnantaki <tnantaki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 23:02:01 by tnantaki          #+#    #+#             */
/*   Updated: 2022/10/16 10:31:57 by tnantaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flag	ft_count_len_fmt(char *nb, t_flag pts)
{
	int	tmp_pis;

	tmp_pis = pts.pis;
	if (nb[0] == '0' && pts.pis)
		pts.len_nb = 0;
	if (pts.pis > pts.len_nb)
		pts.pis = pts.pis - pts.len_nb;
	else
		pts.pis = 0;
	if (pts.wid > pts.pis && pts.wid > (pts.len_nb + pts.len_sign)
		&& pts.wid > tmp_pis)
		pts.wid = pts.wid - pts.pis - pts.len_nb - pts.len_sign;
	else
		pts.wid = 0;
	return (pts);
}

t_flag	ft_write_char(char c, t_flag pts)
{
	if (!pts.minus && !pts.zero && pts.wid)
		pts.len_ptf += ft_putchar_n(' ', pts.wid - 1);
	if (!pts.minus && pts.zero && pts.wid)
		pts.len_ptf += ft_putchar_n('0', pts.wid - 1);
	pts.len_ptf += write(1, &c, 1);
	if (pts.minus && pts.wid)
		pts.len_ptf += ft_putchar_n(' ', pts.wid - 1);
	return (pts);
}

t_flag	ft_write_str(char *s, t_flag pts)
{
	if (!s)
		s = "(null)";
	pts.len_nb = ft_strlen(s);
	if (pts.pis || pts.dot)
	{
		if (pts.pis < pts.len_nb)
			pts.len_nb = pts.pis;
	}
	if (pts.wid > pts.len_nb)
		pts.wid = pts.wid - pts.len_nb;
	else
		pts.wid = 0;
	if (!pts.minus && !pts.zero && pts.wid)
		pts.len_ptf += ft_putchar_n(' ', pts.wid);
	if (!pts.minus && pts.zero && pts.wid)
		pts.len_ptf += ft_putchar_n('0', pts.wid);
	pts.len_ptf += ft_putstr_n(s, pts.len_nb);
	if (pts.minus && pts.wid)
		pts.len_ptf += ft_putchar_n(' ', pts.wid);
	return (pts);
}

t_flag	ft_write_nb(char *nb, t_flag pts)
{
	pts.len_nb = ft_strlen(nb);
	if (pts.negative || pts.plus || pts.space)
		pts.len_sign = 1;
	pts = ft_count_len_fmt(nb, pts);
	if (!pts.minus && !pts.zero && pts.wid)
		pts.len_ptf += ft_putchar_n(' ', pts.wid);
	if (pts.negative)
		pts.len_ptf += ft_putchar('-');
	else if (pts.plus)
		pts.len_ptf += ft_putchar('+');
	else if (pts.space)
		pts.len_ptf += ft_putchar(' ');
	if (!pts.minus && pts.zero && pts.wid)
		pts.len_ptf += ft_putchar_n('0', pts.wid);
	if (pts.pis)
		pts.len_ptf += ft_putchar_n('0', pts.pis);
	pts.len_ptf += ft_putstr(nb);
	if (pts.minus && pts.wid)
		pts.len_ptf += ft_putchar_n(' ', pts.wid);
	return (pts);
}

t_flag	ft_write_nb16(char *nb, t_flag pts, char k)
{
	pts.len_nb = ft_strlen(nb);
	if (k == 'p' || (nb[0] != '0' && pts.hash && (k == 'x' || k == 'X')))
		pts.len_sign = 2;
	pts = ft_count_len_fmt(nb, pts);
	if (!pts.minus && !pts.zero && pts.wid)
		pts.len_ptf += ft_putchar_n(' ', pts.wid);
	if (pts.hash || k == 'p')
	{
		if (k == 'p')
			pts.len_ptf += ft_putstr("0x");
		else if (k == 'x' && nb[0] != '0')
			pts.len_ptf += ft_putstr("0x");
		else if (k == 'X' && nb[0] != '0')
			pts.len_ptf += ft_putstr("0X");
	}
	if (!pts.minus && pts.zero && pts.wid)
		pts.len_ptf += ft_putchar_n('0', pts.wid);
	if (pts.pis)
		pts.len_ptf += ft_putchar_n('0', pts.pis);
	pts.len_ptf += ft_putstr(nb);
	if (pts.minus && pts.wid)
		pts.len_ptf += ft_putchar_n(' ', pts.wid);
	return (pts);
}
/*
int main(void)
{
	t_flag pts;

	pts.plus = '+';
	int l = ft_write_nb("3483", pts);
	printf("\n%d\n", l);

}
*/
