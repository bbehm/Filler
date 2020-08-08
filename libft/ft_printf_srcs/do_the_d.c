/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:00:51 by bbehm             #+#    #+#             */
/*   Updated: 2020/06/30 10:13:22 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

/*
** The typecast function casts the output to the correct type according
** to the length specifiers.
*/

static void		typecast_d(t_tab *tab)
{
	if (tab->length == 'a')
		tab->output = (long)va_arg(tab->args, void*);
	else if (tab->length == 'A')
		tab->output = (long long)va_arg(tab->args, void*);
	else if (tab->length == 'h')
		tab->output = (short)va_arg(tab->args, void*);
	else if (tab->length == 'H')
		tab->output = (char)va_arg(tab->args, void*);
	else
		tab->output = va_arg(tab->args, int);
}

static void		do_final(t_tab *tab)
{
	if (tab->minus)
	{
		if (tab->output < 0)
		{
			ft_putchar_size('-', tab->size);
			tab->output *= -1;
		}
		if (!(tab->num && tab->output == 0))
			ft_putnbr_size(tab->output, tab->size);
		if (tab->output >= 0 && (tab->plus || tab->space) &&\
			!(tab->precision < tab->len) && !tab->sign)
			tab->len += 1;
		if (tab->sign == 1 && !(tab->precision < tab->len))
			tab->len += 1;
		ft_put_spaces(tab->width, tab->len, tab->size);
		return ;
	}
	if (tab->num && tab->output == 0)
		return ;
	ft_putnbr_size(tab->output, tab->size);
}

static void		do_further(t_tab *tab)
{
	if (tab->space && !tab->minus && tab->width &&\
		!tab->zero && !tab->precision)
		ft_put_spaces(tab->width, tab->len, tab->size);
	if (tab->output >= 0 && (tab->plus || tab->space))
		tab->plus ? ft_put_plus(tab->size) : ft_put_space(tab->size);
	if (tab->precision || tab->zero)
	{
		if (tab->output < 0)
		{
			ft_putchar_size('-', tab->size);
			tab->output *= -1;
			tab->sign = 1;
		}
		if (tab->precision)
			ft_put_zeros(tab->precision, &tab->len, tab->size);
		if (tab->zero && !tab->precision && !tab->minus)
			ft_put_zeros(tab->width, &tab->len, tab->size);
	}
	do_final(tab);
}

static void		do_more(t_tab *tab)
{
	if (tab->width && !tab->zero && !tab->space && !tab->minus &&\
		!tab->precision)
		ft_put_spaces(tab->width, tab->len, tab->size);
	if (tab->width && tab->precision && !tab->minus)
	{
		if (tab->precision < tab->width && tab->precision > tab->len)
		{
			if (tab->plus || tab->space || tab->output < 0)
				ft_put_spaces(tab->width, tab->precision + 1, tab->size);
			else
				ft_put_spaces(tab->width, tab->precision, tab->size);
		}
		else if (tab->width > tab->precision && tab->width > tab->len)
			ft_put_spaces(tab->width, tab->len, tab->size);
	}
	do_further(tab);
}

/*
** This function handles the %d and %i flags, checks for additional flags
** and outputs the correct stuff.
*/

void			do_the_d(t_tab *tab)
{
	typecast_d(tab);
	tab->len = ft_intlen(tab->output);
	if (tab->output >= 0 && (tab->plus || tab->space) &&\
		tab->precision < tab->width && tab->precision <= tab->len)
		tab->len = tab->len + 1;
	if (tab->precision >= tab->len && tab->output < 0)
		tab->len = tab->len - 1;
	tab->num && tab->output == 0 ? tab->len = 0 : 0;
	if (tab->num && tab->output == 0 && (tab->plus || tab->space))
		tab->len = 1;
	do_more(tab);
}
