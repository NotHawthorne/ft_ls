/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:15:48 by alkozma           #+#    #+#             */
/*   Updated: 2019/07/01 14:33:14 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;

	i = 0;
	ret = 0;
	if (s1 && s2)
	{
		if (!(ret = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
			return (NULL);
		while (*s1)
			ret[i++] = *s1++;
		while (*s2)
			ret[i++] = *s2++;
		ret[i] = '\0';
	}
	return (ret);
}

char	*ft_strjoin_tok(char const *s1, char const *s2, char tok)
{
	char	*ret;
	int		i;

	i = 0;
	ret = 0;
	if (s1 && s2)
	{
		if (!(ret = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 2)))
			return (NULL);
		while (*s1)
			ret[i++] = *s1++;
		ret[i++] = tok;
		while (*s2)
			ret[i++] = *s2++;
		ret[i] = '\0';
	}
	return (ret);
}
