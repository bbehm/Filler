/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 12:05:28 by bbehm             #+#    #+#             */
/*   Updated: 2020/09/21 15:36:22 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define EMPTY 0
# define ENEMY -2
# define ME -1
# define SHAPE 1

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"

typedef	struct	s_struct
{
	int		**map;
	int		**piece;
	char	me;
	char	opponent;
	int		map_height;
	int		map_width;
	int		piece_height;
	int		piece_width;
	int		min_x;
	int		max_x;
	int		min_y;
	int		max_y;
	int		best[3];
	int		on_top;
	int		rating;
}				t_struct;

int				get_piece(t_struct *info, char *line);
int				**create_box(int width, int height);
void			heatmap(t_struct *info);
int				get_map(t_struct *info, char *line);
void			free_piece(t_struct *info);
void			final_free(t_struct *info);
void			place_piece(t_struct *info);
void			map_score(t_struct *info);

#endif
