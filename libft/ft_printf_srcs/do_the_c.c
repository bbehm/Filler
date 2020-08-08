/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_the_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 15:54:04 by bbehm             #+#    #+#             */
/*   Updated: 2020/06/29 14:05:34 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

/*
** This function handles character conversion. Checks for flags and formats
** output accordingly.
*/

void	do_the_c(t_tab *tab)
{
	char output;

	output = (char)va_arg(tab->args, int);
	if (tab->width && !tab->minus)
		ft_put_spaces(tab->width, 1, tab->size);
	if (tab->minus)
	{
		ft_putchar_size(output, tab->size);
		ft_put_spaces(tab->width, 1, tab->size);
		return ;
	}
	ft_putchar_size(output, tab->size);
}
