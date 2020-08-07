/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 12:04:46 by bbehm             #+#    #+#             */
/*   Updated: 2020/08/07 12:58:41 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../libft/includes/libft.h"

/*
** Initializes the info struct
*/

static t_struct	*initialize(t_struct *info)
{
	if (!(info = (t_struct *)malloc(sizeof(t_struct))))
		return (NULL);
	info->map = NULL;
	info->map_width = 0;
	info->map_height = 0;
	info->piece_height = 0;
	info->piece_width = 0;
	info->piece_max_x = -1;
	info->piece_max_y = -1;
	info->piece_min_x = -1;
	info->piece_min_y = -1;
	return (info);
}

/*
** Checks who is Player 1 and assigns characters accordingly
*/

static int		get_player_char(t_struct *info, int num)
{
	if (num != 1 && num != 2)
		return (-1);
	if (num == 1)
	{
		info->me = 'O';
		info->opponent = 'X';
	}
	else
	{
		info->me = 'X';
		info->opponent = 'O';
	}
	return (0);
}

/*
** The game loop, first it collects relevant info on player characters
** and map outline, then keeps on reading pieces and sends pieces to
** the heatmap and piece placing function.
*/

static int		do_the_loop(t_struct *info, int fd)
{
	char *line;

	while (ft_get_next_line(fd, &line) > 0)
	{
		if (ft_strncmp("$$$", line, 3) == 0)
		{
			if (get_player_char(info, ft_atoi(&line[10])))
				return (-1);
		}
		else if (ft_strncmp("Plateau", line, 7) == 0)
		{
			if (get_map(info, &line[8]))
				return (-1),
			map_score(info);
		}
		else if (ft_strncmp("Piece", line, 5) == 0)
		{
			if (get_piece(info, &line[6]))
				return (-1);
			place_piece(info);
			free_piece(info);
		}
		ft_strdel(&line);
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_struct	*info;
	int		fd;
	int		ret_val;

	fd = 0;
	ret_val = 0;
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	if (!(info = initialize(info)))
		return (-1);
	if (do_the_loop(info, fd) == -1)
		ret_val = 1;
	final_free(info);
	return (0);
}