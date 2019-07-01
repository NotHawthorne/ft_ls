/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 15:59:24 by alkozma           #+#    #+#             */
/*   Updated: 2019/07/01 16:00:11 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		time_compare(struct stat astat, struct stat bstat,
						long atime, long btime)
{
	if (bstat.st_mtime == astat.st_mtime)
		return (btime == atime ? 0 : btime - atime);
	else
		return (bstat.st_mtime - astat.st_mtime);
}
