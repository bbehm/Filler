/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:07:28 by bbehm             #+#    #+#             */
/*   Updated: 2019/11/11 15:49:18 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int i;

	i = 0;
	while (s1 && s2 && s1[i] == s2[i])
	{
		if ((s1[i + 1] == '\0') && (s2[i + 1] == '\0'))
			return (1);
		i++;
	}
	return (0);
}
