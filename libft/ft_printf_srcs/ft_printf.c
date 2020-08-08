/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:58:55 by bbehm             #+#    #+#             */
/*   Updated: 2020/06/25 17:23:37 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>
#include "../includes/ft_printf.h"
#include "../libft/includes/libft.h"

int	ft_printf(const char *format, ...)
{
	t_tab	tab;
	int		size;

	size = 0;
	tab.i = -1;
	tab.size = &size;
	va_start(tab.args, format);
	while (format[++tab.i] != '\0')
	{
		initialize(&tab);
		if (format[tab.i] == '%')
			parse(&tab, format);
		else
			ft_putchar_size(format[tab.i], tab.size);
		if (format[tab.i] == '\0')
			return (0);
	}
	va_end(tab.args);
	return (*tab.size);
}
