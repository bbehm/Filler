/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 14:39:41 by bbehm             #+#    #+#             */
/*   Updated: 2020/06/29 14:34:30 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

/*
** fix precision checks for precision specifiers in format string and stores
** formatting instructions in the struct.
*/

static void		continue_precision(t_tab *tab, const char *format)
{
	if ((format[tab->i] > '0' && format[tab->i] <= '9') &&\
	format[tab->i] != '\0')
	{
		tab->precision = ft_atoi(&format[tab->i]);
		while (format[tab->i] >= '0' && format[tab->i] <= '9')
			tab->i++;
		tab->num = 0;
	}
	tab->i = tab->i - 1;
	parse(tab, format);
}

void			fix_precision(t_tab *tab, const char *format)
{
	tab->i = tab->i + 1;
	if (!(format[tab->i] >= '0' && format[tab->i] <= '9') &&\
	format[tab->i] != '*')
		tab->num = -2;
	if (format[tab->i] != '\0' &&\
	(format[tab->i] == '0' || format[tab->i] == '*'))
	{
		if (format[tab->i] == '*')
		{
			tab->precision = va_arg(tab->args, int);
			tab->precision == 0 ? tab->num = -1 : 0;
			tab->precision < 0 ? tab->precision = 0 : 0;
		}
		if (format[tab->i] == '0')
			tab->num = -1;
		tab->i = tab->i + 1;
	}
	continue_precision(tab, format);
}
