/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 21:51:47 by alkozma           #+#    #+#             */
/*   Updated: 2019/07/01 14:14:35 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		half_list(t_queue *list, t_queue **front, t_queue **back)
{
	t_queue *a;
	t_queue *b;

	if (!list)
		return ;
	a = list;
	b = list->next;
	while (b)
	{
		b = b->next;
		if (b)
		{
			a = a->next;
			b = b->next;
		}
	}
	*front = list;
	*back = a->next;
	a->next = NULL;
}

void		move_node(t_queue **a, t_queue **b)
{
	t_queue	*tmp;

	tmp = *b;
	if (!tmp)
		return ;
	else
	{
		*b = tmp->next;
		tmp->next = *a;
		*a = tmp;
	}
}

t_queue		*sorted_merge(t_queue *a, t_queue *b, char flags, int mode)
{
	t_queue d;
	t_queue *tmp;

	tmp = &d;
	d.next = NULL;
	while (1)
	{
		if (!a || !b)
		{
			tmp->next = !a ? b : a;
			break ;
		}
		if (ft_ls_compare(a->path, b->path, flags, mode) < 0)
			move_node(&(tmp->next), &a);
		else
			move_node(&(tmp->next), &b);
		tmp = tmp->next;
	}
	return (d.next);
}

void		merge_sort(t_queue **list, char flags, int mode)
{
	t_queue *head;
	t_queue *a;
	t_queue *b;

	head = *list;
	if (!head || !head->next)
		return ;
	half_list(head, &a, &b);
	merge_sort(&a, flags, mode);
	merge_sort(&b, flags, mode);
	*list = sorted_merge(a, b, flags, mode);
}

void		print_file(char flags, struct stat filestat,
		t_queue **q, t_padding pad)
{
	if (!S_ISDIR(filestat.st_mode))
	{
		if (flags & 1)
			print_long_data(filestat, q, pad);
		else
			ft_printf("%s", (*q)->name);
		write(1, "\n", 1);
	}
}
