/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_strategy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 13:10:02 by bbehm             #+#    #+#             */
/*   Updated: 2020/09/21 15:42:58 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** Result returning help function. Prints the coordinates of the best rated
** spot to put the piece according to the heatmap.
*/

static void	return_result(t_struct *info)
{
	if (info->best[0] > 0)
	{
		ft_putnbr(info->best[1]);
		ft_putstr(" ");
		ft_putnbr(info->best[2]);
		ft_putstr("\n");
	}
	else
	{
		ft_putnbr(0);
		ft_putstr(" ");
		ft_putnbr(0);
		ft_putstr("\n");
	}
}

static int	give_me_space(t_struct *info, int y, int x)
{
	if ((y >= info->map_height) ||\
	(x >= info->map_width) || info->map[y][x] == ENEMY)
		return (-1);
	else if (info->map[y][x] == ME)
	{
		info->on_top++;
		if (info->on_top == 2)
			return (-1);
	}
	else
		info->rating += info->map[y][x];
	return (0);
}

static int	try_place(t_struct *info, int y, int x)
{
	int y_index;
	int x_index;

	y_index = 0;
	info->on_top = 0;
	info->rating = 0;
	while (y_index < info->piece_height)
	{
		x_index = 0;
		while (x_index < info->piece_width)
		{
			if (info->piece[y_index][x_index] == SHAPE)
			{
				if (give_me_space(info, y + y_index, x + x_index) == -1)
					return (-1);
			}
			x_index++;
		}
		y_index++;
	}
	if (info->on_top != 1)
		return (-1);
	return (info->rating);
}

/*
** In place_piece we try to place the given piece in different places,
** omce a 'legal' place is found, we calculate the score of the placement
** by adding up the heatmap scores. The function always compares the
** score to the best one and after parsing through the whole map it
** passes on the best possible place coordinates to the return_result
** function.
*/

void		place_piece(t_struct *info)
{
	int y;
	int x;

	y = 0;
	info->best[0] = 0;
	while ((info->map_height - info->max_y) > (y - info->min_y))
	{
		x = 0;
		while ((info->map_width - info->max_x) > (x - info->min_x))
		{
			if ((info->rating =\
			try_place(info, y - info->min_y, x - info->min_x)) > 0)
			{
				if (info->rating < info->best[0] || info->best[0] == 0)
				{
					info->best[0] = info->rating;
					info->best[1] = y - info->min_y;
					info->best[2] = x - info->min_x;
				}
			}
			x++;
		}
		y++;
	}
	return_result(info);
}
