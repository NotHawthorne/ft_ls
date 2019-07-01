/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 18:52:59 by alkozma           #+#    #+#             */
/*   Updated: 2019/02/12 17:09:49 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	a = (unsigned char*)dst;
	b = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		a[i] = b[i];
		if (b[i] == (unsigned char)c)
			return (dst + 1 + i);
		i++;
	}
	return (NULL);
}
