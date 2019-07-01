/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:39:31 by alkozma           #+#    #+#             */
/*   Updated: 2019/03/13 18:24:35 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		num_len(intmax_t n, int base)
{
	int			i;
	intmax_t	b;

	i = 1;
	b = n;
	while (b /= base)
		i++;
	return (i);
}

char	*convert_base(t_printf *p, int i, int base, int mode)
{
	char			hex[16];
	int				a;
	int				b;
	char			*ret;

	handle_sign(p, i, base);
	i = i < 0 ? -i : i;
	if (mode == 0)
		ft_strcpy(hex, "0123456789ABCDEF");
	else
		ft_strcpy(hex, "0123456789abcdef");
	a = i;
	b = num_len(i, base);
	if (!(ret = (char*)malloc(sizeof(char) * (b + 1))))
		return (0);
	ret[b] = '\0';
	while (b)
	{
		ret[--b] = hex[a % base];
		a /= base;
	}
	return (ret);
}

int		get_padding(t_printf *p)
{
	int ret;

	ret = 0;
	while (*p->format >= '0' && *p->format <= '9')
	{
		if (*p->format == '0' && ret == 0)
		{
			p->zero_pad = 1;
			p->format++;
		}
		else
		{
			ret *= 10;
			ret += *p->format - '0';
			p->format++;
		}
	}
	return (ret + p->zero_pad);
}

int		ft_printf_pad(t_printf *p, int before, int size)
{
	char	c;
	int		ret;
	int		a;

	ret = 0;
	a = p->padding;
	c = p->zero_pad == 1 ? '0' : ' ';
	if (p->padding < p->precision)
		a = p->precision;
	if (before != p->left_justify)
		ret += pad_helper(p, a, size, c);
	return (ret);
}

int		handle_sign(t_printf *p, intmax_t n, int base)
{
	int ret;
	int	len;

	ret = 0;
	if (n < 0)
		p->negative = 1;
	ret += handle_sign_helper(p, 1, n, base);
	len = num_len(n, base);
	if (!p->precision && p->precision_found)
		len = 0;
	if (base == 16 && p->pound == 1 && !p->left_justify)
		p->padding -= 2;
	putspc(p, n);
	ret += ft_printf_pad(p, 1, len + (n < 0 || p->force_sign ? 1 : 0));
	ret += handle_sign_helper(p, 0, n, base);
	return (ret);
}
