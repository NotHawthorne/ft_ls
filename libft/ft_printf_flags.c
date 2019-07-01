/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:43:50 by alkozma           #+#    #+#             */
/*   Updated: 2019/03/13 18:24:46 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_flag(char c)
{
	if (c == '#' || c == '-' || c == '+' ||
			(c >= '0' && c <= '9') || c == '.')
		return (1);
	return (0);
}

int		is_length(char c)
{
	if (c == 'h' || c == 'l' || c == 'L' ||
			c == 'z' || c == 'j')
		return (1);
	return (0);
}

void	handle_flags(t_printf *p)
{
	while (is_flag(*p->format))
	{
		if (*p->format == '#')
			p->pound = 1;
		if (*p->format == '-')
			p->left_justify = 1;
		if (*p->format == '+')
			p->force_sign = 1;
		if (*p->format >= '0' && *p->format <= '9'
				&& *(p->format - 1) != '.' && *(p->format + 1) != ' ')
			p->padding = get_padding(p);
		else if (*p->format == '.')
		{
			p->precision_found = 1;
			p->precision = get_precision(p);
		}
		else
			p->format++;
	}
	if (p->zero_pad == 1 && p->left_justify == 1)
		p->zero_pad = 0;
	handle_size(p);
}

void	handle_size(t_printf *p)
{
	while (is_length(*p->format))
	{
		if (*p->format == 'l' && p->l < 2)
			p->l += 1;
		if (*p->format == 'h' && p->h < 2)
			p->h += 1;
		if (*p->format == 'L')
			p->ll = 1;
		if (*p->format == 'z')
			p->z = 1;
		if (*p->format == 'j')
			p->j = 1;
		p->format++;
	}
}

int		handle_pound(t_printf *p, int mode)
{
	char	c;

	if (*p->format == 'p')
		c = 'x';
	else
		c = *p->format;
	if (p->pound == 1)
	{
		if (mode == 0)
		{
			ft_putchar('0');
			ft_putchar(c);
			return (2);
		}
		else if (mode == 1)
		{
			ft_putchar('0');
			return (1);
		}
	}
	return (0);
}
