/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_zeros.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 11:47:08 by bbehm             #+#    #+#             */
/*   Updated: 2020/06/29 14:49:41 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_put_zeros(int max, int *length, int *bytes)
{
	int i;
	int count;

	i = 0;
	count = max - *length;
	if (max < *length)
		return ;
	while (i < count)
	{
		write(1, "0", 1);
		i++;
		*length = *length + 1;
		*bytes = *bytes + 1;
	}
}
