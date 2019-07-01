/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:46:37 by alkozma           #+#    #+#             */
/*   Updated: 2019/03/13 18:24:17 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_printf	p;
	int			ret;

	ret = 0;
	va_start(p.vargs, (char*)format);
	init_printf(&p);
	p.format = (char*)format;
	while (*p.format)
	{
		if (*p.format == '%')
		{
			p.format++;
			ret += big_boi_handler(&p);
		}
		else if (*p.format != '\0')
		{
			ft_putchar(*p.format);
			ret++;
		}
		p.format++;
	}
	return (ret);
}

int		handle_spaces(t_printf *p)
{
	if (ft_isspace(*p->format))
	{
		while (ft_isspace(*p->format))
			p->format++;
		p->space = 1;
		return (1);
	}
	return (0);
}

void	init_printf(t_printf *p)
{
	p->format = NULL;
	p->left_justify = 0;
	p->padding = 0;
	p->zero_pad = 0;
	p->force_sign = 0;
	p->pound = 0;
	p->space = 0;
	p->precision = 0;
	p->precision_found = 0;
	p->l = 0;
	p->h = 0;
	p->ll = 0;
	p->j = 0;
	p->z = 0;
	p->sign = 0;
	p->sign_printed = 0;
	p->negative = 0;
}

int		handle_sign_helper(t_printf *p, int before, intmax_t n, int base)
{
	int ret;

	ret = 0;
	if (p->zero_pad == 1 && before == 1 && base == 10)
	{
		if (n < 0 && p->sign_printed == 0)
			ft_putchar('-');
		if (n >= 0 && p->force_sign == 1 && p->sign_printed == 0)
			ft_putchar('+');
		if (p->sign_printed == 0 && (n < 0 || (n >= 0 && p->force_sign == 1)))
			p->sign_printed = 1;
		p->padding--;
		ret += (p->force_sign || n < 0 ? 1 : 0) - p->space;
	}
	else if (p->zero_pad == 0 && before == 0 && base == 10)
	{
		if (n < 0 && p->sign_printed == 0)
			ft_putchar('-');
		else if (p->force_sign == 1 && p->sign_printed == 0)
			ft_putchar('+');
		if (n < 0 || p->force_sign == 1)
			ret += 1 - p->space;
		ret -= p->space;
	}
	return (ret);
}

int		pad_helper(t_printf *p, int a, int size, char c)
{
	int ret;

	ret = 0;
	a -= size;
	while (a-- > 0)
	{
		if (p->precision > 0 && a >= p->precision - size)
			ft_putchar(' ');
		else if (p->precision > 0 && a < p->precision - size &&
				p->sign == 1 && p->sign_printed == 0)
		{
			p->sign_printed = 1;
			ft_putstr(p->negative ? "-0" : "+0");
		}
		else if (p->precision > 0 && a < p->precision - size)
			ft_putchar('0');
		else
			ft_putchar(c);
		ret++;
	}
	p->padding = 0;
	p->precision = 0;
	return (ret);
}
