/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 16:26:05 by alkozma           #+#    #+#             */
/*   Updated: 2019/02/13 18:07:49 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char			*ret;
	int				len;
	int				cpy;
	unsigned int	num;

	num = n < 0 ? -n : n;
	cpy = n;
	len = 1;
	while (cpy /= 10)
		len++;
	len += n < 0 ? 1 : 0;
	if (!(ret = (char*)ft_strnew(len)))
		return (NULL);
	ret[--len] = (num % 10) + 48;
	while (num /= 10)
		ret[--len] = (num % 10) + 48;
	*ret = n < 0 ? '-' : *ret;
	return (ret);
}
