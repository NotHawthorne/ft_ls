/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:08:45 by alkozma           #+#    #+#             */
/*   Updated: 2019/02/14 20:46:59 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	i = 0;
	ret = 0;
	if (s)
	{
		if (!(ret = (char*)malloc(len + 1)))
			return (NULL);
		while (len-- > 0)
		{
			ret[i] = s[start + i];
			i++;
		}
		ret[i] = '\0';
	}
	return (ret);
}
