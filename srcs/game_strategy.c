/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_strategy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 13:10:02 by bbehm             #+#    #+#             */
/*   Updated: 2020/08/08 15:13:15 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../libft/includes/libft.h"

/*
** Checks if rating is best so far and saves info in struct
*/

static void	compare_rating(t_struct *info, int rating, int y, int x)
{
	if (rating < info->best_ratings[0] || info->best_ratings[0] == 0)
	{
		info->best_ratings[0] = rating;
		info->best_ratings[1] = y - info->min_y;
		info->best_ratings[2] = x - info->min_x;
	}
}

static int	try_placing_two(t_struct *info, int y, int x, int y_index)
{
	int x_index;
	
	while (y_index < info->piece_height)
	{
		x_index = 0;
		while (x_index < info->piece_width)
		{
			if (info->piece[y_index][x_index] == 1)
			{
				if ((y + y_index >= info->map_height) ||\
				(x + x_index >= info->map_width) || info->map[y + y_index][x + x_index] == ENEMY)
					return (-1);
				else if (info->map[y + y_index][x + x_index] == ME)
				{
					info->edge++;
					if (info->edge == 2)
						return (-1);
				}
				else
					info->rating += info->map[y + y_index][x + x_index];
			}
			x_index++;
		}
		y_index++;
	}
	if (info->edge == 1)
		return (info->rating);
	return (-1);
}

static int	try_placing(t_struct *info, int y, int x)
{
	int y_index;

	y_index = 0;
	info->edge = 0;
	info->rating = 0;
	return (try_placing_two(info, y, x, y_index));
}

void		place_piece(t_struct *info)
{
	int y;
	int x;
	int rating;

	y = 0;
	info->best_ratings[0] = 0;
	while ((info->map_width - info->max_y) > (y - info->min_y))
	{
		x = 0;
		while ((info->map_width - info->max_x) > (x - info->min_x))
		{
			rating = try_placing(info, y - info->min_y, x - info->min_x);
			if (rating > 0)
				compare_rating(info, rating, y, x);
			x++;
		}
		y++;
	}
	info->best_ratings[0] > 0 ? ft_printf("%d %d\n",\
	info->best_ratings[1], info->best_ratings[2]) : ft_printf("%d %d\n", 0, 0);
}
