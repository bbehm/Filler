/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 16:30:43 by bbehm             #+#    #+#             */
/*   Updated: 2020/07/02 19:17:31 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

/*
** The do_the_s function takes care of string conversions, checks for
** additional flags and formats the output accordingly.
*/

static void	do_more_s(t_tab *tab, char *output)
{
	if (tab->width && !tab->minus)
		ft_put_spaces(tab->width, tab->len, tab->size);
	if (tab->minus)
	{
		if (!(tab->num && tab->output == 0))
			ft_putstr_size(output, tab->size);
		ft_put_spaces(tab->width, tab->len, tab->size);
		if (tab->precision)
			free(output);
		return ;
	}
	if (tab->num)
		return ;
	ft_putstr_size(output, tab->size);
	if (tab->precision)
		free(output);
}

void		do_the_s(t_tab *tab)
{
	char *output;

	output = va_arg(tab->args, char*);
	if (output == NULL)
		output = "(null)";
	if (!tab->num)
		tab->len = ft_strlen(output);
	else
		tab->len = 0;
	if (tab->width && tab->zero && !tab->minus && !tab->precision)
		ft_put_zeros(tab->width, &tab->len, tab->size);
	if (tab->precision)
	{
		output = ft_strsub(output, 0, tab->precision);
		tab->len = ft_strlen(output);
	}
	do_more_s(tab, output);
}
