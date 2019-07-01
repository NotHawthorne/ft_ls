/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 10:08:25 by alkozma           #+#    #+#             */
/*   Updated: 2019/07/01 13:38:34 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	read_flags(char *flag_str, char flags)
{
	char	ret;

	ret = 0;
	while (flag_str && *flag_str)
	{
		if (*flag_str == 'l' && !(flags & 1))
			ret += LONG_FORMAT;
		if (*flag_str == 'R' && !(flags >> 1 & 1))
			ret += RECURSIVE;
		if (*flag_str == 'a' && !(flags >> 2 & 1))
			ret += HIDDEN_FILES;
		if (*flag_str == 'r' && !(flags >> 3 & 1))
			ret += REVERSE_SORT;
		if (*flag_str++ == 't' && !(flags >> 4 & 1))
			ret += TIME_SORT;
	}
	return (ret);
}

static void	read_input(char flags, char **dir_str, int files, t_padding pad)
{
	struct stat filestat;

	lstat(*dir_str, &filestat);
	if (S_ISDIR(filestat.st_mode))
		if (files > 0)
			ft_printf("\n%s:\n", *dir_str);
	ft_ls(*dir_str, flags, S_ISDIR(filestat.st_mode) ? 1 : 0, pad);
	free(*dir_str);
	*dir_str = NULL;
}

void		ft_ls(char *path, char flags, int mode, t_padding pad)
{
	t_queue		*q;
	DIR			*curdir;
	int			i;
	struct stat filestat;

	q = NULL;
	add_dir(&q, path, path, mode);
	i = 0;
	while (q)
	{
		if (lstat(q->path, &filestat) < 0 ||
				(!(curdir = opendir(q->path)) && S_ISDIR(filestat.st_mode)))
			ft_printf("\nft_ls: %s: %s\n", q->path, strerror(errno));
		else
		{
			if (i > 0 && S_ISDIR(filestat.st_mode))
				ft_printf("\n%s:\n", q->path, i);
			S_ISDIR(filestat.st_mode) ? print_dir(flags, curdir, &q)
				: print_file(flags, filestat, &q, pad);
		}
		pop_dir(&q);
		merge_sort(&q, flags, mode);
		i++;
	}
}

t_queue		*init_queue(char **argv, int pos, char flags)
{
	t_queue		*q;
	t_queue		*fq;
	struct stat	filestat;
	int			i;

	q = NULL;
	i = pos;
	fq = NULL;
	while (argv[i])
	{
		if (lstat(argv[i], &filestat) < 0)
			ft_printf("ft_ls: %s: %s\n", argv[i], strerror(errno));
		else if (S_ISDIR(filestat.st_mode))
			add_dir(&q, argv[i], argv[i], S_ISDIR(filestat.st_mode) ? 1 : 0);
		else
			add_dir(&fq, argv[i], argv[i], S_ISDIR(filestat.st_mode) ? 1 : 0);
		i++;
	}
	merge_init_q(&fq, &q, flags, 1);
	if (!fq && !q && i == pos)
		add_dir(&q, ".", ".", 1);
	return (fq ? fq : q);
}

int			main(int argc, char **argv)
{
	static char		flags;
	static int		i;
	static int		files;
	t_queue			*q;
	t_padding		pad;

	i = 1;
	while (argc > i && argv[i][0] == '-')
		flags += read_flags(argv[i++], flags);
	q = init_queue(argv, i, flags);
	pad = calc_padding(&q);
	while (q)
	{
		read_input(flags, &(q->name), files++, pad);
		pop_dir(&q);
	}
}
