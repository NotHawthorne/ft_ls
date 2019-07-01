/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 10:12:59 by alkozma           #+#    #+#             */
/*   Updated: 2019/07/01 16:31:37 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_basic_permissions(struct stat filestat)
{
	ft_printf(S_ISDIR(filestat.st_mode) ? "d" : "");
	ft_printf(S_ISLNK(filestat.st_mode) ? "l" : "");
	ft_printf(S_ISCHR(filestat.st_mode) ? "c" : "");
	ft_printf(S_ISBLK(filestat.st_mode) ? "b" : "");
	ft_printf(S_ISFIFO(filestat.st_mode) ? "p" : "");
	ft_printf(S_ISSOCK(filestat.st_mode) ? "s" : "");
	ft_printf(S_ISREG(filestat.st_mode) ? "-" : "");
	ft_printf(filestat.st_mode & S_IRUSR ? "r" : "-");
	ft_printf(filestat.st_mode & S_IWUSR ? "w" : "-");
	ft_printf(filestat.st_mode & S_ISUID &&
			!(filestat.st_mode & S_IXUSR) ? "S" : "");
	ft_printf(filestat.st_mode & S_ISUID &&
			filestat.st_mode & S_IXUSR ? "s" : "");
	ft_printf(!(filestat.st_mode & S_ISUID) &&
			filestat.st_mode & S_IXUSR ? "x" : "");
	ft_printf(!(filestat.st_mode & S_ISUID) &&
			!(filestat.st_mode & S_IXUSR) ? "-" : "");
	ft_printf(filestat.st_mode & S_IRGRP ? "r" : "-");
	ft_printf(filestat.st_mode & S_IWGRP ? "w" : "-");
}

void	print_permissions(struct stat filestat)
{
	print_basic_permissions(filestat);
	ft_printf(filestat.st_mode & S_ISGID &&
			!(filestat.st_mode & S_IXGRP) ? "S" : "");
	ft_printf(filestat.st_mode & S_ISGID &&
			filestat.st_mode & S_IXGRP ? "s" : "");
	ft_printf(!(filestat.st_mode & S_ISGID) &&
			filestat.st_mode & S_IXGRP ? "x" : "");
	ft_printf(!(filestat.st_mode & S_ISGID) &&
			!(filestat.st_mode & S_IXGRP) ? "-" : "");
	ft_printf(filestat.st_mode & S_IROTH ? "r" : "-");
	ft_printf(filestat.st_mode & S_IWOTH ? "w" : "-");
	ft_printf(filestat.st_mode & S_ISVTX &&
			!(filestat.st_mode & S_IXOTH) ? "T  " : "");
	ft_printf(filestat.st_mode & S_ISVTX &&
			filestat.st_mode & S_IXOTH ? "t  " : "");
	ft_printf(!(filestat.st_mode & S_ISVTX) &&
			filestat.st_mode & S_IXOTH ? "x  " : "");
	ft_printf(!(filestat.st_mode & S_ISVTX) &&
			!(filestat.st_mode & S_IXOTH) ? "-  " : "");
}

void	print_long_data(struct stat filestat, t_queue **q, t_padding pad)
{
	char		*curtime;
	char		buf[1024];

	curtime = print_time(filestat);
	print_permissions(filestat);
	ft_pad(pad.links - num_sz(filestat.st_nlink));
	ft_printf("%d %s  ", filestat.st_nlink, getpwuid(filestat.st_uid)
			? getpwuid(filestat.st_uid)->pw_name : ft_itoa(filestat.st_uid));
	ft_pad(pad.pwuid - (getpwuid(filestat.st_uid) ?
			ft_strlen(getpwuid(filestat.st_uid)->pw_name) :
			num_sz(filestat.st_uid)));
	ft_printf("%s  ", getgrgid(filestat.st_gid)
			? getgrgid(filestat.st_gid)->gr_name : ft_itoa(filestat.st_gid));
	ft_pad(pad.grgid - (getgrgid(filestat.st_gid) ?
			ft_strlen(getgrgid(filestat.st_gid)->gr_name) :
			num_sz(filestat.st_gid)));
	ft_pad(pad.size - num_sz(filestat.st_size));
	ft_printf("%d %s %s", filestat.st_size, curtime, (*q)->name);
	if (S_ISLNK(filestat.st_mode))
	{
		ft_memset(buf, 0, sizeof(buf));
		readlink((*q)->path, buf, sizeof(buf) - 1);
		ft_printf(" -> %s", buf);
	}
	free(curtime);
}

void	print_list(t_queue **q, char flags, int size)
{
	struct stat	curstat;
	t_queue		*tmp;
	t_padding	pad;

	pad = calc_padding(q);
	tmp = *q;
	if (tmp)
	{
		merge_sort(&tmp, flags, 0);
		if (flags & 1)
			ft_printf("total: %d\n", size);
	}
	while (tmp)
	{
		lstat(tmp->path, &curstat);
		if (flags & 1)
			print_long_data(curstat, &tmp, pad);
		else
			ft_printf("%s  ", tmp->name);
		write(1, "\n", 1);
		pop_dir(&tmp);
	}
}

void	print_dir(char flags, DIR *curdir, t_queue **orig_q)
{
	struct dirent	*curfile;
	struct stat		curstat;
	t_queue			*q;
	char			*buf;
	int				i;

	i = 1;
	q = NULL;
	while ((curfile = readdir(curdir)) != NULL)
	{
		buf = ft_strjoin((*orig_q)->path, curfile->d_name);
		if (lstat(buf, &curstat) < 0)
			ft_printf("ft_ls: %s: %s", buf, strerror(errno));
		else
		{
			if (check_dir(curstat, flags, curfile))
				add_dir(orig_q, buf, curfile->d_name, 1);
			if ((curfile->d_name[0] != '.' || flags >> 2 & 1)
					&& (i += (int)curstat.st_blocks))
				add_dir(&q, buf, curfile->d_name, 0);
		}
		free(buf);
	}
	print_list(&q, flags, i - 1);
	closedir(curdir);
}
