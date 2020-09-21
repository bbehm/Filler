# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbehm <bbehm@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/06 12:02:04 by bbehm             #+#    #+#              #
#    Updated: 2020/09/21 11:15:47 by bbehm            ###   ########.fr        #
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
OBJS =	main.o \
		free_helpers.o \
		game_strategy.o \
		map_utilities.o \
		piece_utilities.o \
		heatmap.o
INCL = -I includes/
LIB = -L libft -lft

all: $(NAME)

$(NAME):
	@make -C libft
	@gcc $(FLAGS) -c $(SRCS) $(INCL)
	@gcc $(FLAGS) $(INCL) $(OBJS) $(LIB) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all

.PHONY: all clean flcean re