/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 12:38:53 by bbehm             #+#    #+#             */
/*   Updated: 2020/06/29 14:57:28 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_intlen_u(unsigned long long value)
{
	int		tens;

	tens = 1;
	while (value / 10)
	{
		value = value / 10;
		tens++;
	}
	return (tens);
}
