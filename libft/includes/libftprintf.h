/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 13:39:16 by alkozma           #+#    #+#             */
/*   Updated: 2019/03/10 16:52:13 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <inttypes.h>

# define TABLE_SIZE 12

typedef struct			s_printf
{
	char				*format;
	va_list				vargs;
	int					left_justify;
	int					padding;
	int					zero_pad;
	int					force_sign;
	int					pound;
	int					space;
	int					precision;
	int					precision_found;
	int					l;
	int					h;
	int					ll;
	int					j;
	int					z;
	int					sign;
	int					sign_printed;
	int					negative;
}						t_printf;

int						ft_printf(const char *format, ...);

int						handle_char(t_printf *p);
int						handle_string(t_printf *p);
int						handle_integer(t_printf *p);
int						handle_hex(t_printf *p);
int						handle_octal(t_printf *p);
int						handle_uint(t_printf *p);
int						handle_float(t_printf *p);
int						handle_pointer(t_printf *p);

int						big_boi_handler(t_printf *p);

int						(**g_build_table(void))(t_printf *p);

void					init_printf(t_printf *p);
void					handle_flags(t_printf *p);
int						get_padding(t_printf *p);
int						get_precision(t_printf *p);
int						ft_printf_pad(t_printf *p, int before, int size);
int						pad_helper(t_printf *p, int a, int size, char c);
int						handle_sign(t_printf *p, intmax_t n, int base);
int						handle_sign_helper(t_printf *p, int before,
							intmax_t n, int base);
int						handle_sign_dbl(t_printf *p, long double n);
int						handle_sign_helper_dbl(t_printf *p,
							int before, long double n);
int						handle_spaces(t_printf *p);
int						handle_pound(t_printf *p, int mode);
int						handle_precision(t_printf *p, int base, int size);
void					handle_size(t_printf *p);
intmax_t				read_number(t_printf *p);
uintmax_t				read_number_uns(t_printf *p);
long double				read_number_dbl(t_printf *p);
int						putspc(t_printf *p, intmax_t n);
int						putspc_uns(t_printf *p);

int						num_len(intmax_t n, int base);
int						num_len_uns(uintmax_t n, int base);
int						num_len_dbl(long double n, t_printf *p);
char					*convert_base(t_printf *p, int i, int base, int mode);
char					*convert_unsigned_base(t_printf *p,
							uintmax_t i, int base, int mode);
void					ft_putnbr_nosign(intmax_t n);
void					ft_putnbr_uns(uintmax_t n);
void					ft_putdbl(long double n, t_printf *p);

#endif
