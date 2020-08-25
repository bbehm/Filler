/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 12:52:27 by bbehm             #+#    #+#             */
/*   Updated: 2020/08/25 13:58:52 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** Creates an integer array of zeros - used for both the map and individual
** pieces
*/

int		**create_box(int width, int height)
{
	int **map;
	int	y;
	int i;

	if (!(map = (int**)malloc(sizeof(int*) * height)))
		return (NULL);
	y = 0;
	while (y < height)
	{
		if (!(map[y] = (int*)malloc(width * sizeof(int))))
			return (NULL);
		i = 0;
		while (i < width)
		{
			map[y][i] = 0;
			i++;
		}
		y++;
	}
	return (map);
}

int				get_map(t_struct *info, char *line)
{
	if (info->map == NULL)
	{
		info->map_height = ft_atoi(line);
		while (line && *line != ' ')
			line++;
		line++;
		info->map_width = ft_atoi(line);
		if (info->map_height < 1 || info->map_width < 1)
			return (1);
		if (!(info->map = create_box(info->map_width, info->map_height)))
			return (1);
	}
	heatmap(info);
	return (0);
}
