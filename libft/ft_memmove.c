/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 20:24:35 by alkozma           #+#    #+#             */
/*   Updated: 2019/02/13 12:51:15 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dsts;
	unsigned char	*srcs;
	size_t			i;

	dsts = (unsigned char*)dst;
	srcs = (unsigned char*)src;
	i = 0;
	if (srcs < dsts)
	{
		while (len > 0)
		{
			len--;
			dsts[len] = srcs[len];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return ((unsigned char*)dst);
}
