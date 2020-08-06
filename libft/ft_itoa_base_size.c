/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 10:38:57 by bbehm             #+#    #+#             */
/*   Updated: 2020/06/29 14:53:52 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void			print_result(char *res, int *size, char flag)
{
	int len;
	int i;

	i = 0;
	len = ft_strlen(res);
	if (len < 8 && flag == 'b')
	{
		while (i++ < (8 - len))
			ft_putchar_size('0', size);
	}
	ft_putstr_size(res, size);
	free(res);
}

static unsigned int	num_len(unsigned long long value, int base)
{
	unsigned long long	len;

	len = 1;
	if (value < 0 && base == 10)
		len++;
	while (value / base)
	{
		len++;
		value /= base;
	}
	return (len);
}

int					ft_itoa_base_size(unsigned long long value,\
int base, int *size, char flag)
{
	unsigned long long	length;
	char				*res;
	char				*base_str;

	if (flag == 'x' || flag == 'p')
		base_str = "0123456789abcdef";
	else
		base_str = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (0);
	length = num_len(value, base);
	if (!(res = (char*)malloc(sizeof(*res) * (length + 1))))
		return (0);
	res[length--] = '\0';
	res[0] = (value < 0 && base == 10 ? '-' : '0');
	if (value < 0)
		value = -1 * value;
	while (value > 0)
	{
		res[length--] = base_str[value % base];
		value /= base;
	}
	print_result(res, size, flag);
	return (1);
}
