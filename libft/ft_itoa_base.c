/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/23 10:25:41 by bbehm             #+#    #+#             */
/*   Updated: 2020/06/29 14:55:29 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

/*
** First, we check if the value is zero, if not we count how long the string
** will be with the indicated base and store it in num_len. Then, we
** take the original value and check if it's negative. If negative,
** we convert it to unsigned. If the base however is 10 we need to add
** one to num_len to allocate space for minus sign.
** Now we allocate space for the string we will return. After that we
** add the null terminator to the string.
** Then it's time to convert the value into the correct base, this can be done
** by taking the modulo of the base from the number, and choosing that point
** from the base string and storing it in the result string.
** Finally, we add the minus sign if it's a negative value in base 10, and then
** return the result string (ptr).
*/

static unsigned int	num_len(unsigned long long value, int base)
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

char				*ft_itoa_base(unsigned long long value, int base)
{
	int					size;
	unsigned long long	nbr;
	char				*res;
	char				*str_base;

	nbr = value;
	str_base = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (NULL);
	size = num_len(nbr, base);
	if (!(res = (char*)malloc(sizeof(*res) * (size + 1))))
		return (NULL);
	res[size--] = '\0';
	res[0] = (nbr < 0 && base == 10 ? '-' : '0');
	if (nbr < 0)
		nbr = -nbr;
	while (nbr > 0)
	{
		res[size--] = str_base[nbr % base];
		nbr /= base;
	}
	return (res);
}
