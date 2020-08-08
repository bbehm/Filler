/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 15:05:28 by bbehm             #+#    #+#             */
/*   Updated: 2020/06/29 14:44:42 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

/*
** Percent flag handles the situation where there's a double %% in which
** case we want to print the % instead of handling it as a flag.
*/

void	percent_flag(t_tab *tab)
{
	tab->len = 1;
	if (!tab->minus && tab->zero)
		ft_put_zeros(tab->width, &tab->len, tab->size);
	if (!tab->zero && !tab->minus && tab->width)
		ft_put_spaces(tab->width, 1, tab->size);
	if (tab->minus)
	{
		ft_putchar_size('%', tab->size);
		ft_put_spaces(tab->width, 1, tab->size);
		return ;
	}
	ft_putchar_size('%', tab->size);
}
