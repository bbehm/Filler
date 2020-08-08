/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 17:20:07 by bbehm             #+#    #+#             */
/*   Updated: 2020/07/09 13:30:07 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

/*
** The do_the_p function takes care of pointer conversions, checks for
** additional flags and formats the output accordingly.
*/

static void	ft_put_zeros_twist(int max, int length, int *bytes)
{
	int i;
	int count;

	i = 0;
	count = max - length;
	if (max < length)
		return ;
	while (i < count)
	{
		write(1, "0", 1);
		i++;
		length = length + 1;
		*bytes = *bytes + 1;
	}
}

static void	do_more_p(t_tab *tab, char flag)
{
	if (tab->width > tab->precision && tab->precision)
		ft_put_spaces(tab->width,\
		((int)ft_intlen_u(tab->output_u) + 1), tab->size);
	ft_putstr_size("0x", tab->size);
	if (tab->output_u == 0 && tab->num)
		return ;
	if (tab->precision)
	{
		if (tab->output_u == 0)
			ft_put_zeros_twist(tab->precision,\
			((int)ft_intlen_u(tab->output_u)), tab->size);
		else
			ft_put_zeros_twist(tab->precision,\
			((int)ft_intlen_u(tab->output_u) - 1), tab->size);
	}
	ft_itoa_base_size(tab->output_u, 16, tab->size, flag);
}

void		do_the_p(t_tab *tab, char flag)
{
	tab->output_u = (unsigned long)va_arg(tab->args, void*);
	tab->nbr = ft_itoa_base_ul(tab->output_u, 16);
	if (!tab->minus && tab->width && !tab->precision)
		ft_put_spaces(tab->width, ft_strlen(tab->nbr) + 2, tab->size);
	if (tab->minus)
	{
		ft_putstr_size("0x", tab->size);
		if (!(tab->num && tab->output_u == 0))
			ft_itoa_base_size(tab->output_u, 16, tab->size, flag);
		ft_put_spaces(tab->width, ft_strlen(tab->nbr) + 2, tab->size);
		free(tab->nbr);
		return ;
	}
	free(tab->nbr);
	do_more_p(tab, flag);
}
