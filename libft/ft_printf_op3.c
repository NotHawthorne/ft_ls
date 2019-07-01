/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:34:29 by alkozma           #+#    #+#             */
/*   Updated: 2019/03/13 18:25:18 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_uns(uintmax_t n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar('0' + (n % 10));
}

int		putspc(t_printf *p, intmax_t n)
{
	if (n >= 0 && p->force_sign == 0 && p->padding == 0
			&& p->space == 1)
		ft_putchar(' ');
	return (1);
}

int		putspc_uns(t_printf *p)
{
	if (p->force_sign == 0 && p->padding == 0 &&
			p->space == 1)
	{
		ft_putchar(' ');
		return (1);
	}
	return (0);
}

void	ft_putdbl(long double n, t_printf *p)
{
	uintmax_t	left;
	long double	tmp;
	long double num;
	int			precision;

	num = n;
	num = num < 0 ? -num : num;
	left = (uintmax_t)num;
	tmp = num - left;
	precision = p->precision > 0 ? p->precision : 6;
	ft_putnbr(left);
	ft_putchar('.');
	while (precision--)
	{
		tmp *= 10;
		ft_putnbr((int)tmp);
		tmp -= (int)tmp;
	}
}

int		num_len_dbl(long double n, t_printf *p)
{
	uintmax_t	left;
	uintmax_t	right;
	long double	num;
	int			precision;
	long double	tmp;

	num = n;
	num = num < 0 ? -num : num;
	left = (uintmax_t)num;
	tmp = num - left;
	right = 0;
	precision = p->precision > 0 ? p->precision : 6;
	return (num_len_uns(left, 10) + precision);
}
