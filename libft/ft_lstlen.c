/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:21:18 by alkozma           #+#    #+#             */
/*   Updated: 2019/02/14 12:23:29 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstlen(t_list *lst)
{
	t_list	*tmp;
	size_t	ret;

	tmp = lst;
	ret = 0;
	while (tmp)
	{
		tmp = tmp->next;
		ret++;
	}
	return (ret);
}
