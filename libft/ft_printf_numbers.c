/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:31:52 by alkozma           #+#    #+#             */
/*   Updated: 2019/03/13 18:24:57 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_integer(t_printf *p)
{
	intmax_t		a;
	int				len;
	int				pad;

	a = read_number(p);
	p->sign = a < 0 || p->force_sign == 1 ? 1 : 0;
	p->precision += (a < 0 || p->force_sign) && p->precision > 0 &&
		!p->left_justify ? 1 : 0;
	len = num_len(a, 10);
	pad = handle_sign(p, a, 10);
	pad += handle_precision(p, 10, len);
	ft_putnbr_nosign(a);
	if (p->space && !p->precision_found)
		len++;
	return (len + pad);
}

int		handle_uint(t_printf *p)
{
	uintmax_t	a;
	int			len;
	int			pad;

	if (*p->format == 'U')
		p->l = 1;
	a = read_number_uns(p);
	len = num_len_uns(a, 10);
	putspc_uns(p);
	p->padding -= p->zero_pad;
	pad = ft_printf_pad(p, 1, num_len_uns(a, 10));
	ft_putnbr_uns(a);
	return (len + pad);
}

int		handle_hex(t_printf *p)
{
	uintmax_t		a;
	int				len;
	int				pad;

	a = read_number_uns(p);
	p->padding -= p->zero_pad;
	if (!p->precision && p->precision_found)
	{
		pad = handle_sign(p, a, 16);
		return (pad);
	}
	len = num_len_uns(a, 16);
	if (p->zero_pad)
		len += handle_pound(p, 0);
	pad = handle_sign(p, a, 16);
	if (!p->zero_pad && a != 0)
		len += handle_pound(p, 0);
	if (*p->format == 'X')
		ft_putstr(convert_unsigned_base(p, a, 16, 0));
	else
		ft_putstr(convert_unsigned_base(p, a, 16, 1));
	return (len + pad);
}

int		handle_octal(t_printf *p)
{
	uintmax_t	a;
	int			len;
	int			pad;

	a = read_number_uns(p);
	if (!p->precision && p->precision_found)
	{
		pad = handle_sign(p, a, 8);
		pad += handle_pound(p, 1);
		return (pad);
	}
	if (p->zero_pad)
		p->padding--;
	if (p->pound && !p->left_justify)
		p->padding--;
	len = num_len_uns(a, 8);
	pad = handle_sign(p, a, 8);
	pad += handle_precision(p, 8, len);
	if ((a != 0 && p->pound == 1) || p->pound == 0)
		ft_putstr(convert_unsigned_base(p, a, 8, 0));
	else
		len--;
	return (len + pad);
}

int		handle_float(t_printf *p)
{
	long double	a;
	int			len;
	int			pad;

	a = read_number_dbl(p);
	p->sign = 1;
	len = num_len_dbl(a, p) + 1;
	putspc(p, a);
	pad = handle_sign_dbl(p, a);
	ft_putdbl(a, p);
	return (len + pad);
}
