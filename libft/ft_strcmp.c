/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:16:18 by alkozma           #+#    #+#             */
/*   Updated: 2019/02/14 14:11:23 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	a;
	unsigned char	b;

	if (ft_strlen(s1) == 0 && ft_strlen(s2) > 0)
		return (-1);
	if (ft_strlen(s1) > 0 && ft_strlen(s2) == 0)
		return (1);
	while (*s1 || *s2)
	{
		a = *(unsigned char*)s1;
		b = *(unsigned char*)s2;
		if (a != b)
			return (a - b);
		s1++;
		s2++;
	}
	return (0);
}
