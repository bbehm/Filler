/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ul.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 16:24:03 by bbehm             #+#    #+#             */
/*   Updated: 2020/07/02 18:46:20 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static unsigned int	num_len(long value, int base)
{
	int	size;

	size = 1;
	if (value < 0 && base == 10)
		size++;
	while (value / base)
	{
		size++;
		value /= base;
	}
	return (size);
}

char				*ft_itoa_base_ul(unsigned long long value, int base)
{
	int				size;
	char			*res;
	char			*base_str;

	base_str = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (0);
	size = num_len(value, base);
	if (!(res = (char*)malloc(sizeof(*res) * (size + 1))))
		return (0);
	res[size--] = '\0';
	res[0] = (value < 0 && base == 10 ? '-' : '0');
	if (value < 0)
		value = -value;
	while (value > 0)
	{
		res[size--] = base_str[value % base];
		value /= base;
	}
	return (res);
}
