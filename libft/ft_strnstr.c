/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:37:18 by alkozma           #+#    #+#             */
/*   Updated: 2019/02/14 20:09:04 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*tst;

	tst = (char*)haystack;
	if (!*needle)
		return (tst);
	while (len-- && *haystack != '\0')
	{
		i = 0;
		while (*(tst + i) == (char)needle[i] && len >= i)
		{
			if (++i == ft_strlen(needle))
				return ((char*)haystack);
		}
		tst++;
		haystack++;
	}
	return (NULL);
}
