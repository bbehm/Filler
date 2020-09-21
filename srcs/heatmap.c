/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 14:29:52 by bbehm             #+#    #+#             */
/*   Updated: 2020/09/21 12:48:21 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			chase_opponent(t_struct *info, int y, int x)
{
	int y_two;
	int x_two;
	int	current_best;
	int best;

	y_two = 0;
	best = 0;
	while (y_two < info->map_height)
	{
		x_two = 0;
		while (x_two < info->map_width)
		{
			if (info->map[y_two][x_two] == ENEMY)
			{
				current_best = y_two > y ? y_two - y : y - y_two;
				current_best += x_two > x ? x_two - x : x - x_two;
				if (current_best < best || best == 0)
					best = current_best;
			}
			x_two++;
		}
		y_two++;
	}
	return (best);
}

void		map_score(t_struct *info)
{
	int y;
	int x;

	y = 0;
	while (y < info->map_height)
	{
		x = 0;
		while (x < info->map_width)
		{
			if (info->map[y][x] == EMPTY)
				info->map[y][x] = chase_opponent(info, y, x);
			x++;
		}
		y++;
	}
}

void		map_existing(t_struct *info, int y, char *line)
{
	int x;

	x = 0;
	while (x < info->map_width)
	{
		if (line[x] == info->me || line[x] == info->me + 32)
			info->map[y][x] = ME;
		else if (line[x] == info->opponent ||\
		line[x] == info->opponent + 32)
			info->map[y][x] = ENEMY;
		else
			info->map[y][x] = EMPTY;
		x++;
	}
}

/*
** Function for creating a heatmap to map out which places are strategically
** good choices to place pieces. First, it maps out empty, enemy, and own
** places. Then, for every empty place, it calculates a score according to
** how close the enemy is - our aim is to place the piece as close to the
** enemy as possible to block them from placing pieces.
*/

void		heatmap(t_struct *info)
{
	char	*line;
	char	*hold;
	int		y;

	y = 0;
	get_next_line(0, &line);
	ft_strdel(&line);
	while (y < info->map_height && get_next_line(0, &line) > 0)
	{
		hold = line;
		while ((*line >= '0' && *line <= '9') || *line == ' ')
			line++;
		map_existing(info, y, line);
		ft_strdel(&hold);
		y++;
	}
}
