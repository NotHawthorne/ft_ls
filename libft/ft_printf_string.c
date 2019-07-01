/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:10:16 by alkozma           #+#    #+#             */
/*   Updated: 2019/03/13 18:25:37 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_char(t_printf *p)
{
	char	c;
	int		pad;

	if (*p->format == '%')
		c = *p->format;
	else
		c = va_arg(p->vargs, int);
	pad = ft_printf_pad(p, 1, 1);
	ft_putchar(c);
	return (1 + pad - p->space);
}

int		handle_string(t_printf *p)
{
	char	*str;
	int		pad;
	int		i;
	int		len;

	len = 0;
	i = 0;
	str = va_arg(p->vargs, char*);
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (!*str && !p->padding)
		return (0);
	len = p->precision ? p->precision : (int)ft_strlen(str);
	pad = ft_printf_pad(p, 1, len);
	while (i++ < len)
	{
		if (!*str)
			ft_putchar(' ');
		else
			ft_putchar(*str++);
	}
	return (len + pad);
}

int		handle_pointer(t_printf *p)
{
	intmax_t	a;
	int			len;
	int			pad;

	a = va_arg(p->vargs, long long int);
	p->pound = 1;
	len = num_len(a, 16);
	pad = handle_sign(p, a, 16);
	handle_pound(p, 0);
	ft_putstr(convert_unsigned_base(p, a, 16, 1));
	return (len + pad);
}

int		handle_precision(t_printf *p, int base, int size)
{
	int ret;

	ret = 0;
	if (base == 8 || base == 10)
	{
		if (p->precision > p->padding)
			p->padding = 0;
		while (p->precision > size)
		{
			ft_putchar('0');
			p->precision--;
			ret++;
		}
	}
	if (p->pound == 1 && (base == 8 || base == 10))
	{
		ft_putchar('0');
		return (1);
	}
	return (ret);
}

int		handle_sign_helper_dbl(t_printf *p, int before, long double n)
{
	int	ret;

	ret = 0;
	if (p->zero_pad == 1 && before == 1)
	{
		if (n < 0)
			ft_putchar('-');
		if (n >= 0 && p->force_sign == 1)
			ft_putchar('+');
		p->padding = p->force_sign == 1 && n < 0 ? p->padding - 1 : p->padding;
		if (n < 0 || p->force_sign == 1)
			ret++;
		ret += 1 - p->space;
	}
	else if (p->zero_pad == 0 && before == 0)
	{
		if (n < 0)
			ft_putchar('-');
		else if (p->force_sign == 1)
			ft_putchar('+');
		if (n < 0 || p->force_sign == 1)
			ret += 1 - p->space;
	}
	return (ret);
}
