/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:37:27 by alkozma           #+#    #+#             */
/*   Updated: 2019/02/14 12:52:22 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*ret;
	t_list	*head;

	tmp = f(lst);
	if (!(ret = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	head = ret;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(ret->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		ret = ret->next;
		lst = lst->next;
	}
	return (head);
}
