/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 12:17:52 by bbehm             #+#    #+#             */
/*   Updated: 2020/09/21 11:47:39 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** Function for freeing map and struct at the end of program
*/

void	final_free(t_struct *info)
{
	int i;

	i = 0;
	while (i < info->map_height)
	{
		free(info->map[i]);
		i++;
	}
	free(info->map);
	free(info);
}

/*
** Function for freeing pieces as we proceed in the game
*/

void	free_piece(t_struct *info)
{
	int i;

	i = 0;
	while (i < info->piece_height)
	{
		free(info->piece[i]);
		i++;
	}
	free(info->piece);
}
