/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:43:48 by alkozma           #+#    #+#             */
/*   Updated: 2019/03/10 18:33:47 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

static t_list	*find_file(int fd, t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	if (fd < 0)
		return (NULL);
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(lst, tmp);
	tmp = *lst;
	return (tmp);
}

static int		tokloc(char *str, char c)
{
	int i;

	i = 0;
	if (!ft_strchr(str, c))
		return (-1);
	while (str[i] != c)
		i++;
	return (i);
}

static void		strbecome(char **dst, char *src)
{
	char	*tmp;

	tmp = ft_strjoin(*dst, src);
	ft_strdel(dst);
	*dst = tmp;
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	int				i;
	int				read_bytes;
	char			buf[BUFF_SIZE + 1];
	t_list			*tst;

	MEMCHK((fd < 4865 && fd >= 0 && (tst = find_file(fd, &lst))));
	CONTENTCHK(((char*)tst->content) && *line);
	while (!ft_strchr((char*)tst->content, '\n') &&
			(read_bytes = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[read_bytes] = '\0';
		strbecome((char**)&tst->content, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (!ft_strlen((char*)tst->content))
		return (read_bytes);
	i = tokloc((char*)tst->content, '\n');
	*line = i >= 0 ? ft_strsub((char*)tst->content, 0, i)
		: ft_strdup((char*)tst->content);
	tst->content = i >= 0 ? ft_strslc((char*)tst->content, 0, i) : tst->content;
	if (i == -1)
		ft_strdel((char**)&tst->content);
	return (1);
}
