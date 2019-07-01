/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:18:46 by alkozma           #+#    #+#             */
/*   Updated: 2019/02/14 20:45:07 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ret;
	int		start;
	int		end;
	int		i;

	start = 0;
	i = 0;
	ret = 0;
	if (s)
	{
		while (ft_isspace(s[start]) == 1)
			start++;
		end = ft_strlen(s) - 1;
		while (ft_isspace(s[end]) == 1)
			end--;
		if (end == -1)
			return (ft_strnew(1));
		if (!(ret = (char*)malloc(end - start + 2)))
			return (NULL);
		while (start <= end)
			ret[i++] = s[start++];
		ret[i] = '\0';
	}
	return (ret);
}
