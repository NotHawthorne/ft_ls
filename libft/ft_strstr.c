/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 15:37:18 by alkozma           #+#    #+#             */
/*   Updated: 2019/02/12 17:10:46 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*h_proxy;
	char	*n_proxy;

	if (!*needle)
		return ((char*)haystack);
	while (*haystack)
	{
		h_proxy = (char*)haystack;
		n_proxy = (char*)needle;
		while (*haystack && *n_proxy && *haystack == *n_proxy)
		{
			haystack++;
			n_proxy++;
		}
		if (!*n_proxy)
			return (h_proxy);
		haystack = h_proxy + 1;
	}
	return (NULL);
}
