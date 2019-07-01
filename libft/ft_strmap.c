/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:41:31 by alkozma           #+#    #+#             */
/*   Updated: 2019/02/14 14:43:02 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	int		i;

	i = 0;
	ret = NULL;
	if (s && f)
	{
		if (!(ret = (char*)malloc(ft_strlen(s) + 1)))
			return (NULL);
		while (s[i])
		{
			ret[i] = f(s[i]);
			i++;
		}
		ret[i] = '\0';
	}
	return (ret);
}
