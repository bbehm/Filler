/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 10:50:15 by bbehm             #+#    #+#             */
/*   Updated: 2020/06/29 14:46:27 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbr_size(long long n, int *size)
{
	if (n == -2147483648)
	{
		ft_putchar_size('-', size);
		ft_putnbr_size(2, size);
		ft_putnbr_size(147483648, size);
	}
	else if (n >= 0 && n < 10)
		ft_putchar_size(n + '0', size);
	else if (n >= 10)
	{
		ft_putnbr_size(n / 10, size);
		ft_putchar_size(n % 10 + '0', size);
	}
	else if (n < 0)
	{
		ft_putchar_size('-', size);
		ft_putnbr_size(-n, size);
	}
}
