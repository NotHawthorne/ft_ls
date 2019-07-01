/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:06:44 by alkozma           #+#    #+#             */
/*   Updated: 2019/02/14 20:30:51 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 && s2)
	{
		if (!*s1 && !*s2)
			return (1);
		while (*s1 && *s2 && n-- > 0)
			if (*(unsigned char*)s1++ != *(unsigned char*)s2++)
				return (0);
	}
	return (1);
}
