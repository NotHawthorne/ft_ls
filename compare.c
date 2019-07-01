/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 13:39:42 by alkozma           #+#    #+#             */
/*   Updated: 2019/07/01 16:19:56 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_ls_compare(char *a, char *b, char flags, int mode)
{
	struct stat	astat;
	struct stat	bstat;
	long		atime;
	long		btime;
	int			time_res;

	if (lstat(a, &astat) < 0 || lstat(b, &bstat) < 0)
		return (flags >> 3 & 1 ? ft_strcmp(b, a) : ft_strcmp(a, b));
	atime = astat.st_mtimespec.tv_nsec;
	btime = bstat.st_mtimespec.tv_nsec;
	time_res = time_compare(astat, bstat, atime, btime);
	if (S_ISDIR(astat.st_mode) && !S_ISDIR(bstat.st_mode) && mode == 1)
		return (-1);
	else if (S_ISDIR(bstat.st_mode) && !S_ISDIR(astat.st_mode) && mode == 1)
		return (1);
	else if (flags >> 3 & 1 && !(flags >> 4 & 1))
		return (-(ft_strcmp(a, b)));
	else if (flags >> 4 & 1 && !(flags >> 3 & 1))
		return (time_res != 0 ? time_res : ft_strcmp(a, b));
	else if (flags >> 4 & 1 && flags >> 3 & 1)
		return (time_res != 0 ? -time_res : ft_strcmp(b, a));
	else
		return (ft_strcmp(a, b));
	return (ft_strcmp(a, b));
}

void	add_dir(t_queue **q, char *path, char *name, int mode)
{
	t_queue *tmp;
	t_queue *new;

	new = malloc(sizeof(t_queue));
	new->next = NULL;
	new->path = (mode > 0 && path[ft_strlen(path) - 1] != '/')
		? ft_strjoin(path, "/") : ft_strdup(path);
	new->name = (name && name) ? ft_strdup(name) : NULL;
	tmp = *q;
	if (tmp == NULL)
		*q = new;
	else
	{
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	pop_dir(t_queue **q)
{
	t_queue *tmp;
	t_queue *tmp2;

	tmp = *q;
	tmp2 = *q;
	if (tmp && tmp->next)
	{
		tmp = tmp->next;
		free(tmp2->path);
		free(tmp2->name);
		free(tmp2);
		tmp2 = NULL;
	}
	else
	{
		free(tmp->path);
		free(tmp->name);
		free(tmp);
		tmp = NULL;
	}
	*q = tmp;
}

int		check_dir(struct stat curstat, char flags, struct dirent *curfile)
{
	if (S_ISDIR(curstat.st_mode) && flags >> 1 & 1)
		if (ft_strcmp(curfile->d_name, ".") && ft_strcmp(curfile->d_name, ".."))
			if (curfile->d_name[0] != '.' || flags >> 2 & 1)
				return (1);
	return (0);
}

void	merge_init_q(t_queue **files, t_queue **dirs, char flags, int mode)
{
	t_queue *tmp;

	tmp = *files;
	merge_sort(files, flags, mode);
	merge_sort(dirs, flags, mode);
	if (tmp && dirs)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = *dirs;
	}
}
