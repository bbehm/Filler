# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbehm <bbehm@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/06 12:02:04 by bbehm             #+#    #+#              #
#    Updated: 2020/08/25 14:07:44 by bbehm            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bbehm.filler

SRCS =	srcs/main.c \
		srcs/free_helpers.c \
		srcs/game_strategy.c \
		srcs/map_utilities.c \
		srcs/piece_utilities.c \
		srcs/heatmap.c


FLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)
INCL = -I includes/
LIB = -L libft -lft

all: $(NAME)

$(NAME): libftmake
	@gcc $(FLAGS) $(INCL) $(SRCS) $(LIB) -o $(NAME) -O2

libftmake:
	@make -C libft

clean:
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all

.PHONY: all clean flcean re