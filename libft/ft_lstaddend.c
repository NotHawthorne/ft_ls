/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:28:42 by alkozma           #+#    #+#             */
/*   Updated: 2019/02/14 12:37:20 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddend(t_list *alst, t_list *new)
{
	t_list	*tmp;

	tmp = alst;
	if (alst && new)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
