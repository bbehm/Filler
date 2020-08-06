/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 12:47:36 by bbehm             #+#    #+#             */
/*   Updated: 2020/06/29 14:46:15 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbr_u(unsigned long long n, int *size)
{
	if (n < 0)
	{
		ft_putchar_size('-', size);
		n = -n;
	}
	if (n / 10)
	{
		ft_putnbr_u(n / 10, size);
	}
	*size = *size + 1;
	ft_putchar(n % 10 + '0');
}
