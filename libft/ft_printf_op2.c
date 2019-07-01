/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:45:51 by alkozma           #+#    #+#             */
/*   Updated: 2019/03/13 18:25:09 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_unsigned_base(t_printf *p, uintmax_t i, int base, int mode)
{
	char		hex[16];
	uintmax_t	a;
	int			b;
	char		*ret;

	if (p)
		a = 0;
	if (mode == 0)
		ft_strcpy(hex, "0123456789ABCDEF");
	else
		ft_strcpy(hex, "0123456789abcdef");
	a = i;
	b = num_len_uns(i, base);
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

void	ft_putnbr_nosign(intmax_t n)
{
	if (n > 0)
		n = -n;
	if (n <= -10)
		ft_putnbr(-(n / 10));
	ft_putchar('0' - (n % 10));
}

int		num_len_uns(uintmax_t n, int base)
{
	int			i;
	uintmax_t	b;

	i = 1;
	b = n;
	while (b /= base)
		i++;
	return (i);
}

int		get_precision(t_printf *p)
{
	int		ret;

	ret = 0;
	p->format++;
	while (*p->format >= '0' && *p->format <= '9')
		ret = (10 * ret) + (*p->format++ - '0');
	return (ret);
}

int		handle_sign_dbl(t_printf *p, long double n)
{
	int ret;
	int	len;

	len = num_len_dbl(n, p) + 1;
	len += n < 0 || p->force_sign == 1 ? 1 : 0;
	ret = 0;
	ret += handle_sign_helper_dbl(p, 1, n);
	putspc(p, n);
	ret += ft_printf_pad(p, 1, len);
	ret += handle_sign_helper_dbl(p, 0, n);
	return (ret);
}
