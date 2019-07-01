/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strslc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 12:56:09 by alkozma           #+#    #+#             */
/*   Updated: 2019/06/10 17:57:14 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strslc(char *str, size_t start, size_t end)
{
	size_t	i;
	size_t	plc;
	size_t	len;
	char	*tmp;
	char	*tmp2;

	i = 0;
	plc = 0;
	len = ft_strlen(str) + 1;
	if (!(tmp = ft_strdup(str)))
		return (NULL);
	tmp2 = malloc(sizeof(char) * ((end - start) + 1));
	ft_bzero(tmp2, (end - start + 1));
	while (i <= len)
	{
		if (i >= start && i <= end)
			i++;
		else
			tmp2[plc++] = tmp[i++];
	}
	ft_strdel(&tmp);
	return (tmp2);
}
