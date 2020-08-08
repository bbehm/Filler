/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_utilities.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 12:52:33 by bbehm             #+#    #+#             */
/*   Updated: 2020/08/08 15:37:49 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../libft/includes/libft.h"

/*
** Reinitializes coordinates before looking at a new piece
*/

static void	reinitialize_piece(t_struct *info, char *line)
{
	info->max_x = -1;
	info->max_y = -1;
	info->min_x = -1;
	info->min_y = -1;
	info->piece_height = ft_atoi(line);
	while (line && *line != ' ')
		line++;
	line++;
	info->piece_width = ft_atoi(line);
}

static void	get_more_piece(t_struct *info, int y, char *line)
{
	int x;

	x = 0;
	while (x < info->piece_width)
	{
		if (line[x] == '*')
		{
			info->piece[y][x] = 1;
			if (x < info->min_x || info->min_x == -1)
				info->min_x = x;
			if (x > info->max_x || info->max_x == -1)
				info->max_x = x;
			if (y < info->min_y || info->min_y == -1)
				info->min_y = y;
			if (y > info->max_y || info->max_y == -1)
				info->max_y = y;
		}
		x++;
	}
}

/*
** Checks width, height and coordinates of piece and saves info in
** the struct
*/

int			get_piece(t_struct *info, char *line)
{
	int		y;

	y = 0;
	reinitialize_piece(info, line);
	if (info->piece_width < 1 || info->piece_height < 1)
		return (-1);
	if (!(info->piece = create_box(info->piece_width, info->piece_height)))
		return (-1);
	while (get_next_line(0, &line) > 0 && y < info->piece_height)
	{
		get_more_piece(info, y, line);
		y++;
		ft_strdel(&line);
	}
	return (0);
}
