/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:37:12 by alkozma           #+#    #+#             */
/*   Updated: 2019/03/12 14:24:28 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_elems(char const *s, char c)
{
	char	*tmp;
	int		ret;

	ret = 0;
	tmp = (char*)s;
	while (*tmp)
	{
		if (*tmp == c)
			tmp++;
		else
		{
			ret++;
			while (*tmp != c && *tmp != '\0')
				tmp++;
		}
	}
	return (ret);
}

static char	**ft_strsplit_really(char const *s, char c)
{
	char	**ret;
	int		i;
	int		len;
	int		elems;

	i = 0;
	elems = 0;
	if (!(ret = (char**)ft_memalloc(ft_get_elems(s, c) * (sizeof(char*) + 1))))
		return (NULL);
	while (s[i] && c && elems < ft_get_elems(s, c))
	{
		len = 0;
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] && s[i] != c)
			{
				i++;
				len++;
			}
			ret[elems++] = ft_strsub(s, (unsigned int)(i - len), len);
		}
	}
	return (ret);
}

char		**ft_strsplit(char const *s, char c)
{
	if (!s || !c)
		return (NULL);
	return (ft_strsplit_really(s, c));
}
