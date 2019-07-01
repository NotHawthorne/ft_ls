/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:11:56 by alkozma           #+#    #+#             */
/*   Updated: 2019/06/06 12:24:14 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	int		len;
	int		i;

	len = ft_strlen(s1);
	ret = (char*)ft_memalloc((len + 1) * sizeof(char));
	if (ret != NULL)
	{
		i = 0;
		while (i < len)
		{
			ret[i] = s1[i];
			i++;
		}
		ret[i] = '\0';
		return (ret);
	}
	else
		return (NULL);
}
