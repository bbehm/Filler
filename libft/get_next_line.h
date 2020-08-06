/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbehm <bbehm@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:35:32 by bbehm             #+#    #+#             */
/*   Updated: 2019/11/12 17:15:27 by bbehm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 800

# include <stdlib.h>
# include <unistd.h>
# include "./libft/includes/libft.h"

int	get_next_line(const int fd, char **line);

#endif
