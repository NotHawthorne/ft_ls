/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:59:38 by alkozma           #+#    #+#             */
/*   Updated: 2019/02/14 20:40:30 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (s1 && s2)
	{
		if (!*s1 && !*s2)
			return (1);
		while (*s1 && *s2)
			if (*(unsigned char*)s1++ != *(unsigned char*)s2++)
				return (0);
		if ((!*s1 && *s2) || (*s1 && !*s2))
			return (0);
	}
	return (1);
}
