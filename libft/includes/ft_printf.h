/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:02:03 by bbehm             #+#    #+#             */
/*   Updated: 2020/07/09 14:27:45 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <ctype.h>
# include <stdlib.h>

/*
** This struct holds all the relevant information on flags and info we need to
** display the output correctly.
*/

typedef struct	s_tab
{
	va_list		args;
	int			len;
	int			dot;
	int			hash;
	int			minus;
	int			space;
	int			zero;
	int			plus;
	int			sign;
	int			i;
	int			precision;
	int			width;
	int			num;
	int			base;
	long double	output_f;
	intmax_t	output;
	uintmax_t	output_u;
	char		*nbr;
	char		flag;
	char		length;
	int			*size;
}				t_tab;

int				ft_printf(const char *format, ...);
void			parse(t_tab *tab, const char *format);
void			initialize(t_tab *tab);
void			fix_precision(t_tab *tab, const char *format);
void			fix_width(t_tab *tab, const char *format);
void			do_the_d(t_tab *tab);
void			do_the_c(t_tab *tab);
void			do_the_s(t_tab *tab);
void			do_the_o(t_tab *tab, char flag);
void			do_the_u(t_tab *tab);
void			do_the_x(t_tab *tab, char flag);
void			do_the_p(t_tab *tab, char flag);
void			percent_flag(t_tab *tab);
void			do_the_f(t_tab *tab);
void			do_gap(t_tab *tab, char c, int len, int new_len);
void			show_char(wint_t c, t_tab *tab);
void			fix_h(t_tab *tab, const char *str);
void			fix_hh(t_tab *tab, const char *str);
void			fix_ll(t_tab *tab, const char *str);
void			fix_l(t_tab *tab, const char *str);
void			fix_f(t_tab *tab, const char *str);

#endif
