/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 09:51:35 by alkozma           #+#    #+#             */
/*   Updated: 2019/07/01 15:59:21 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			num_sz(int num)
{
	int	i;
	int ret;

	i = num;
	ret = 1;
	while (i > 9)
	{
		i /= 10;
		ret++;
	}
	return (ret);
}

void		ft_pad(int n)
{
	while (n--)
		write(1, " ", 1);
}

void		do_calc(t_padding *pad, struct stat filestat)
{
	pad->links = num_sz(filestat.st_nlink) > pad->links ?
		num_sz(filestat.st_nlink) : pad->links;
	if (getpwuid(filestat.st_uid))
		pad->pwuid = (int)ft_strlen(getpwuid(filestat.st_uid)->pw_name)
			> pad->pwuid ?
			(int)ft_strlen(getpwuid(filestat.st_uid)->pw_name) : pad->pwuid;
	else
		pad->pwuid = num_sz(filestat.st_uid) > pad->pwuid ?
			num_sz(filestat.st_uid) : pad->pwuid;
	if (getgrgid(filestat.st_gid))
		pad->grgid = (int)ft_strlen(getgrgid(filestat.st_gid)->gr_name)
			> pad->grgid ?
			(int)ft_strlen(getgrgid(filestat.st_gid)->gr_name) : pad->grgid;
	else
		pad->grgid = num_sz(filestat.st_gid) > pad->grgid ?
			num_sz(filestat.st_gid) : pad->grgid;
	pad->size = num_sz(filestat.st_size) > pad->size ?
		num_sz(filestat.st_size) : pad->size;
}

char		*print_time(struct stat filestat)
{
	char	*curtime;
	char	*year;
	char	*mtime;
	char	*month;
	time_t	now;

	time(&now);
	curtime = ctime(&filestat.st_mtime);
	curtime[ft_strlen(curtime) - 1] = ' ';
	year = curtime + 20;
	curtime[ft_strlen(curtime) - 8] = '\0';
	mtime = curtime + 11;
	curtime[16] = '\0';
	month = curtime + 4;
	curtime[10] = '\0';
	if ((int)now - (int)filestat.st_mtime > 31622400)
		return (ft_strjoin_tok(month, year, ' '));
	else
		return (ft_strjoin_tok(month, mtime, ' '));
}

t_padding	calc_padding(t_queue **q)
{
	t_padding	ret;
	t_queue		*tmp;
	struct stat	filestat;

	ret.links = 0;
	ret.pwuid = 0;
	ret.grgid = 0;
	ret.size = 0;
	tmp = *q;
	while (tmp)
	{
		if (lstat(tmp->path, &filestat) >= 0)
			do_calc(&ret, filestat);
		tmp = tmp->next;
	}
	return (ret);
}
