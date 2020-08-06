/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 10:19:36 by bbehm             #+#    #+#             */
/*   Updated: 2020/06/29 14:57:13 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static long double	rounding(long double f, int precision)
{
	long double	rounded;
	int			dec;

	rounded = 0.5;
	dec = 0;
	if (f < 0)
		rounded *= -1;
	while (dec++ < precision)
		rounded /= 10.0;
	return (rounded);
}

char				*ft_ftoa(long double f, int precision, int dot)
{
	unsigned long long	value;
	char				*before_dec;
	char				*after_dec;
	char				*res;
	int					i;

	f = f + rounding(f, precision);
	f *= (f < 0) ? -1 : 1;
	value = f;
	before_dec = ft_itoa(value);
	f = precision ? (f - value) : 0;
	after_dec = ft_strnew(precision + 2);
	after_dec[0] = (dot) ? '.' : '\0';
	i = 1;
	while (precision-- > 0)
	{
		f *= 10;
		value = f;
		f -= value;
		after_dec[i++] = value + '0';
	}
	res = ft_strjoin(before_dec, after_dec);
	free(after_dec);
	free(before_dec);
	return (res);
}
