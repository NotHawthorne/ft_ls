/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 10:09:04 by alkozma           #+#    #+#             */
/*   Updated: 2019/07/01 16:01:17 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define LONG_FORMAT	1
# define RECURSIVE		2
# define HIDDEN_FILES	4
# define REVERSE_SORT	8
# define TIME_SORT		16

# include "includes/ftgnl.h"
# include "includes/ftprintf.h"
# include "includes/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <string.h>
# include <errno.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <errno.h>

typedef struct			s_queue
{
	char				*path;
	char				*name;
	struct s_queue		*next;
}						t_queue;

typedef struct			s_padding
{
	int					links;
	int					pwuid;
	int					grgid;
	int					size;
}						t_padding;

void					print_dir(char flags, DIR *curdir, t_queue **orig_q);
void					ft_ls(char *path, char flags, int mode, t_padding pad);
void					merge_sort(t_queue **list, char flags, int mode);
void					print_long_data(struct stat filestat,
							t_queue **q, t_padding pad);
int						ft_ls_compare(char *a, char *b, char flags, int mode);
void					add_dir(t_queue **q, char *path, char *name, int mode);
void					print_dir(char flags, DIR *curdir, t_queue **orig_q);
void					pop_dir(t_queue **q);
int						check_dir(struct stat curstat, char flags,
							struct dirent *curfile);
void					merge_init_q(t_queue **files, t_queue **dirs,
							char flags, int mode);
void					print_file(char flags, struct stat filestat,
							t_queue **q, t_padding pad);
t_padding				calc_padding(t_queue **q);
void					ft_pad(int n);
int						num_sz(int num);
char					*print_time(struct stat filestat);
int						time_compare(struct stat astat, struct stat bstat,
										long atime, long btime);

#endif
