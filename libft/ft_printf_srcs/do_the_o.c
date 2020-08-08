/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:19:52 by bbehm             #+#    #+#             */
/*   Updated: 2020/06/29 14:16:21 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

/*
** The do_the_o function takes care of octal conversions, checks for
** additional flags and formats the output accordingly.
** The typecast function casts the output to the correct type according
** to the length specifiers.
*/

static void	typecast_u(t_tab *tab)
{
	if (tab->length == 'a')
		tab->output_u = (unsigned long)va_arg(tab->args, void*);
	else if (tab->length == 'A')
		tab->output_u = (unsigned long long)va_arg(tab->args, void*);
	else if (tab->length == 'h')
		tab->output_u = (unsigned short)va_arg(tab->args, void*);
	else if (tab->length == 'H')
		tab->output_u = (unsigned char)va_arg(tab->args, void*);
	else
		tab->output_u = va_arg(tab->args, unsigned int);
}

static void	do_further_o(t_tab *tab, char flag)
{
	if (tab->hash)
	{
		tab->output_u != 0 ? ft_putchar_size('0', tab->size) : 0;
		if (tab->hash && tab->output_u == 0 &&\
		(tab->num == -2 || tab->num == -1))
			ft_putchar_size('0', tab->size);
	}
	if (tab->minus)
	{
		if (!(tab->num && tab->output_u == 0))
			ft_itoa_base_size(tab->output_u, tab->base, tab->size, flag);
		if (tab->precision < tab->width && tab->precision > tab->len)
			ft_put_spaces(tab->width, tab->precision, tab->size);
		else
			ft_put_spaces(tab->width, tab->len, tab->size);
		return ;
	}
	if (tab->output_u == 0 && tab->num)
		return ;
	ft_itoa_base_size(tab->output_u, tab->base, tab->size, flag);
}

static void	do_more_o(t_tab *tab, char flag)
{
	if (tab->width && !tab->zero && !tab->minus && !tab->precision)
		ft_put_spaces(tab->width, tab->len, tab->size);
	if (tab->width && !tab->minus && tab->precision)
	{
		if (tab->precision < tab->width && tab->precision > tab->len)
			ft_put_spaces(tab->width, tab->precision, tab->size);
		else if (tab->precision < tab->width && tab->width > tab->len)
			ft_put_spaces(tab->width, tab->len, tab->size);
	}
	if (tab->width && tab->zero && !tab->minus && !tab->precision)
		ft_put_zeros(tab->width, &tab->len, tab->size);
	if (tab->zero || tab->precision)
		ft_put_zeros(tab->precision, &tab->len, tab->size);
	do_further_o(tab, flag);
}

void		do_the_o(t_tab *tab, char flag)
{
	typecast_u(tab);
	if (flag == 'o')
		tab->base = 8;
	else
		tab->base = 2;
	tab->nbr = ft_itoa_base(tab->output_u, tab->base);
	if (flag == 'o')
		tab->len = ft_strlen(tab->nbr);
	else
		tab->len = 8;
	free(tab->nbr);
	if (tab->hash && tab->output_u != 0)
		tab->len += 1;
	tab->num && tab->output_u == 0 ? tab->len = 0 : 0;
	tab->num && tab->output == 0 && tab->hash ? tab->len = 1 : 0;
	do_more_o(tab, flag);
}
