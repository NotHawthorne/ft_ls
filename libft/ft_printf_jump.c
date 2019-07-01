/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:49:40 by alkozma           #+#    #+#             */
/*   Updated: 2019/03/13 18:26:40 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		(**g_build_table(void))(t_printf *p)
{
	static int		(*ret[])(t_printf *p) = {
		handle_char,
		handle_string,
		handle_pointer,
		handle_integer,
		handle_integer,
		handle_octal,
		handle_hex,
		handle_hex,
		handle_uint,
		handle_uint,
		handle_float,
		handle_char
	};

	return (ret);
}

int		return_index(char c)
{
	int		i;
	char	str[TABLE_SIZE + 1];

	i = 0;
	ft_strcpy(str, "cspidoxXuUf%");
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		big_boi_handler(t_printf *p)
{
	int		(**table)(t_printf *p);
	int		i;

	i = 0;
	table = g_build_table();
	i += handle_spaces(p);
	handle_flags(p);
	i += table[return_index(*p->format)](p);
	if (p->padding)
		i += ft_printf_pad(p, 0, i);
	return (i);
}
