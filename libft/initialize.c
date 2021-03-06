/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:38:10 by bbehm             #+#    #+#             */
/*   Updated: 2020/08/08 15:50:50 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "includes/libft.h"

/*
** function to initialize struct
*/

void	initialize(t_tab *tab)
{
	tab->plus = 0;
	tab->minus = 0;
	tab->hash = 0;
	tab->space = 0;
	tab->zero = 0;
	tab->dot = 0;
	tab->num = 0;
	tab->width = 0;
	tab->length = 0;
	tab->len = 0;
	tab->precision = 0;
	tab->sign = 0;
	tab->output = 0;
	tab->output_f = 0;
	tab->output_u = 0;
	tab->nbr = 0;
}
