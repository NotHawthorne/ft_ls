/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 18:06:08 by alkozma           #+#    #+#             */
/*   Updated: 2019/03/13 18:24:26 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	read_number(t_printf *p)
{
	intmax_t	a;

	if (p->l == 1)
		a = va_arg(p->vargs, long int);
	else if (p->l == 2)
		a = va_arg(p->vargs, long long int);
	else if (p->z == 1)
		a = va_arg(p->vargs, size_t);
	else if (p->h == 1)
		a = (short int)va_arg(p->vargs, int);
	else if (p->h == 2)
		a = (signed char)va_arg(p->vargs, int);
	else if (p->j == 1)
		a = (intmax_t)va_arg(p->vargs, intmax_t);
	else
		a = va_arg(p->vargs, int);
	return (a);
}

uintmax_t	read_number_uns(t_printf *p)
{
	uintmax_t	a;

	if (p->l == 1)
		a = va_arg(p->vargs, unsigned long int);
	else if (p->l == 2)
		a = va_arg(p->vargs, unsigned long long int);
	else if (p->z == 1)
		a = va_arg(p->vargs, size_t);
	else if (p->j == 1)
		a = va_arg(p->vargs, uintmax_t);
	else
		a = va_arg(p->vargs, unsigned int);
	return (a);
}

long double	read_number_dbl(t_printf *p)
{
	long double	a;

	if (p->ll == 1)
		a = va_arg(p->vargs, long double);
	else
	{
		a = va_arg(p->vargs, double);
		if (p->precision <= 15)
		{
			if (a < 0)
				a -= 0.000000000000001;
			else
				a += 0.000000000000001;
		}
		return ((double)a);
	}
	if (p->precision <= 15)
	{
		if (a < 0)
			a -= 0.000000000000001;
		else
			a += 0.000000000000001;
	}
	return (a);
}
