/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 12:05:28 by bbehm             #+#    #+#             */
/*   Updated: 2020/08/07 12:53:16 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct  s_struct
{
    int     **map;
    int     **piece;
    char    me;
    char    opponent;
    int     map_height;
    int     map_width;
    int     piece_height;
    int     piece_width;
    int     piece_min_x;
    int     piece_max_x;
    int     piece_min_y;
    int     piece_max_y;
}               t_struct;

#endif