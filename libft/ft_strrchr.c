/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 14:22:33 by alkozma           #+#    #+#             */
/*   Updated: 2019/02/12 15:36:59 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int pos;

	i = 0;
	pos = -1;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			pos = i;
		i++;
	}
	if ((char)c == '\0' && s[i] == '\0')
		pos = i;
	if (pos == -1)
		return (NULL);
	else
	{
		i = 0;
		while (i < pos)
		{
			s++;
			i++;
		}
		return ((char*)s);
	}
}
