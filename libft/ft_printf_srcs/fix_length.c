/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:38:47 by bbehm             #+#    #+#             */
/*   Updated: 2020/07/09 14:44:11 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

/*
** fix length has its own functions for all length specifier flags. They
** save the flag into the struct and directs to the correct conversion
** function according to conversion flag.
*/

void	fix_h(t_tab *tab, const char *str)
{
	tab->i++;
	tab->flag = str[tab->i];
	if (tab->flag == 'd' || tab->flag == 'i')
	{
		tab->length = 'h';
		do_the_d(tab);
	}
	else if (tab->flag == 'u')
	{
		tab->length = 'h';
		do_the_u(tab);
	}
	else if (tab->flag == 'o')
	{
		tab->length = 'h';
		do_the_o(tab, tab->flag);
	}
	else if (tab->flag == 'x' || tab->flag == 'X')
	{
		tab->length = 'h';
		do_the_x(tab, tab->flag);
	}
}

void	fix_hh(t_tab *tab, const char *str)
{
	tab->i = tab->i + 2;
	tab->flag = str[tab->i];
	if (tab->flag == 'd' || tab->flag == 'i')
	{
		tab->length = 'H';
		do_the_d(tab);
	}
	else if (tab->flag == 'u')
	{
		tab->length = 'H';
		do_the_u(tab);
	}
	else if (tab->flag == 'o')
	{
		tab->length = 'H';
		do_the_o(tab, tab->flag);
	}
	else if (tab->flag == 'x' || tab->flag == 'X')
	{
		tab->length = 'H';
		do_the_x(tab, tab->flag);
	}
}

void	fix_ll(t_tab *tab, const char *str)
{
	tab->i = tab->i + 2;
	tab->flag = str[tab->i];
	if (tab->flag == 'd' || tab->flag == 'i')
	{
		tab->length = 'A';
		do_the_d(tab);
	}
	else if (tab->flag == 'u')
	{
		tab->length = 'A';
		do_the_u(tab);
	}
	else if (tab->flag == 'o')
	{
		tab->length = 'A';
		do_the_o(tab, tab->flag);
	}
	else if (tab->flag == 'x' || tab->flag == 'X')
	{
		tab->length = 'A';
		do_the_x(tab, tab->flag);
	}
}

void	fix_l(t_tab *tab, const char *str)
{
	tab->i++;
	tab->flag = str[tab->i];
	if (tab->flag == 'd' || tab->flag == 'i')
	{
		tab->length = 'a';
		do_the_d(tab);
	}
	else if (tab->flag == 'u')
	{
		tab->length = 'a';
		do_the_u(tab);
	}
	else if (tab->flag == 'o')
	{
		tab->length = 'a';
		do_the_o(tab, tab->flag);
	}
	else if (tab->flag == 'x' || tab->flag == 'X')
	{
		tab->length = 'a';
		do_the_x(tab, tab->flag);
	}
}

void	fix_f(t_tab *tab, const char *str)
{
	tab->i = tab->i + 1;
	tab->flag = str[tab->i];
	if (str[tab->i - 1] == 'L')
	{
		tab->length = 'a';
		do_the_f(tab);
	}
	else
	{
		do_the_f(tab);
		tab->i = tab->i - 1;
	}
}
