/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 11:24:42 by bbehm             #+#    #+#             */
/*   Updated: 2020/07/14 10:45:30 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

/*
** The do_the_f function takes care of float conversions, checks for
** additional flags and formats the output accordingly.
** The typecast function casts the output to the correct type according
** to the length specifiers.
*/

static void	typecast_f(t_tab *tab)
{
	if (tab->length == 'a')
		tab->output_f = (long double)va_arg(tab->args, long double);
	else
		tab->output_f = (double)va_arg(tab->args, double);
}

static void	do_final_f(t_tab *tab)
{
	if (tab->zero)
	{
		if (tab->sign)
		{
			ft_putchar_size('-', tab->size);
			tab->sign = 0;
		}
		if (tab->zero)
			ft_put_zeros(tab->width, &tab->len, tab->size);
	}
	if (tab->sign && tab->nbr[0] != '-')
		ft_putchar_size('-', tab->size);
	ft_putstr_size(tab->nbr, tab->size);
	free(tab->nbr);
}

static void	do_further_f(t_tab *tab)
{
	if (tab->width && !tab->zero && !tab->space && !tab->minus)
		ft_put_spaces(tab->width, tab->len, tab->size);
	if (tab->output_f >= 0 && (tab->plus || tab->space))
		tab->plus ? ft_put_plus(tab->size) : ft_put_space(tab->size);
	if (tab->space && tab->width && !tab->zero && !tab->minus)
		ft_put_spaces(tab->width, tab->len, tab->size);
	if (tab->minus)
	{
		if (tab->sign)
		{
			ft_putchar_size('-', tab->size);
			tab->sign = 0;
		}
		ft_putstr_size(tab->nbr, tab->size);
		ft_put_spaces(tab->width, tab->len, tab->size);
		free(tab->nbr);
		return ;
	}
	do_final_f(tab);
}

static void	do_more_f(t_tab *tab)
{
	tab->len = ft_strlen(tab->nbr);
	tab->output_f < 0 ? tab->len += 1 : 0;
	if (tab->output_f >= 0 && (tab->plus || tab->space))
		tab->len = tab->len + 1;
	if (tab->num && tab->output_f == 0)
		tab->len = 0;
	if (tab->num && tab->output_f == 0 && (tab->plus || tab->space))
		tab->len = 1;
	do_further_f(tab);
}

void		do_the_f(t_tab *tab)
{
	int round;

	round = tab->precision;
	typecast_f(tab);
	(tab->precision >= 1) ? tab->dot = 1 : 0;
	tab->sign = (tab->output_f < 0) ? 1 : 0;
	if (tab->precision == 0 && !tab->num)
	{
		round = 6;
		tab->dot = 1;
	}
	else if (tab->num && tab->output_f != 0 && tab->hash && !tab->dot)
	{
		tab->dot = 1;
		round = 0;
	}
	tab->nbr = ft_ftoa(tab->output_f, round, tab->dot);
	do_more_f(tab);
}
