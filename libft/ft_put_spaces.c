/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 11:58:48 by bbehm             #+#    #+#             */
/*   Updated: 2020/06/29 14:48:23 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_put_spaces(int min, int size, int *bytes)
{
	int i;

	i = 0;
	if (min < size)
		return ;
	while (i < (min - size))
	{
		ft_putchar(' ');
		i++;
		*bytes = *bytes + 1;
	}
}
