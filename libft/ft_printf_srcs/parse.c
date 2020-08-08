/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:55:38 by bbehm             #+#    #+#             */
/*   Updated: 2020/07/09 14:36:13 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

static void	flags(t_tab *tab, const char *format)
{
	char flag;

	flag = format[tab->i];
	if (flag == '#')
		tab->hash = 1;
	else if (flag == '-')
		tab->minus = 1;
	else if (flag == ' ')
		tab->space = 1;
	else if (flag == '0')
		tab->zero = 1;
	else if (flag == '+')
		tab->plus = 1;
	parse(tab, format);
}

/*
** This function checks field width, precision and +-0 # flags.
** The flags function will then add flag info to struct and move
** on to check next flag.
*/

static void	parse_three(t_tab *tab, const char *format)
{
	char flag;

	flag = format[tab->i];
	flag > '0' && flag <= '9' ? fix_width(tab, format) : 0;
	flag == '*' ? fix_width(tab, format) : 0;
	flag == '.' ? fix_precision(tab, format) : 0;
	flag == '0' ? flags(tab, format) : 0;
	flag == '+' ? flags(tab, format) : 0;
	flag == '-' ? flags(tab, format) : 0;
	flag == '#' ? flags(tab, format) : 0;
	flag == ' ' ? flags(tab, format) : 0;
}

/*
** Parse two handles all the length flags and moves into fix_length.c
** functions.
*/

static void	parse_two(t_tab *tab, const char *format)
{
	char flag;

	flag = format[tab->i];
	flag == 'l' && format[tab->i + 1] == 'f' ? fix_f(tab, format) : 0;
	flag == 'L' && format[tab->i + 1] == 'f' ? fix_f(tab, format) : 0;
	flag == 'h' && format[tab->i + 1] != 'h' ? fix_h(tab, format) : 0;
	flag == 'h' && format[tab->i + 1] == 'h' ? fix_hh(tab, format) : 0;
	flag == 'l' && format[tab->i + 1] != 'l' ? fix_l(tab, format) : 0;
	flag == 'l' && format[tab->i + 1] == 'l' ? fix_ll(tab, format) : 0;
	parse_three(tab, format);
}

/*
** This function parses all conversions and refers into their respective
** functions.
*/

void		parse(t_tab *tab, const char *format)
{
	char flag;

	tab->i++;
	flag = format[tab->i];
	flag == 'i' ? do_the_d(tab) : 0;
	flag == 'd' ? do_the_d(tab) : 0;
	flag == 'u' ? do_the_u(tab) : 0;
	flag == 'x' || flag == 'X' ? do_the_x(tab, flag) : 0;
	flag == 'o' ? do_the_o(tab, flag) : 0;
	flag == 'c' ? do_the_c(tab) : 0;
	flag == 'p' ? do_the_p(tab, flag) : 0;
	flag == 's' ? do_the_s(tab) : 0;
	flag == 'f' ? do_the_f(tab) : 0;
	flag == '%' ? percent_flag(tab) : 0;
	parse_two(tab, format);
}
