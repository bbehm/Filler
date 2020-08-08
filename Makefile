# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbehm <bbehm@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/06 12:02:04 by bbehm             #+#    #+#              #
#    Updated: 2020/08/08 15:24:12 by bbehm            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		bbehm.filler
LIBFT_A =	libft.a

COMP =		gcc -Wall -Werror -Wextra $(FILLER_H) $(LIBFT_H) -c -o

FILLER_H =	-I includes/
LIBFT_H = 	-I srcs/libft/includes

OBJ_DIR =	obj/
SRC_DIR =	srcs/
LIB_DIR =	libft/

CFILE =		main.c \
			free_helpers.c \
			game_strategy.c \
			map_utilities.c \
			piece_utilities.c \
			heatmap.c	

CFIND =		$(CFILE:%=$(SRC_DIR)%)

OFILE =		$(CFILE:%.c=%.o)

OBJ =		$(addprefix $(OBJ_DIR), $(OFILE))

all: $(NAME)

$(OBJ_DIR):
		@mkdir -p $(OBJ_DIR)
		@echo Create: Filler Object directory

$(NAME): $(OBJ_DIR) $(OBJ)
		@echo LIBFT START
		@make -C $(LIB_DIR)
		@echo Copying $(LIBFT_A) to root.
		@cp $(LIB_DIR)$(LIBFT_A) .
		@mv $(LIBFT_A) $(NAME)
		@ar rc $(NAME) $(addprefix $(OBJ_DIR), $(OFILE))
		@ranlib $(NAME)
		@echo Merged: $(NAME) with $(LIBFT_A)
		@echo FILLER COMPLETE

$(OBJ): $(CFIND)
		@$(MAKE) $(OFILE)

$(OFILE):
		@echo Create: $(@:obj/%=%)
		@$(COMP) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

clean:
		@/bin/rm -rf $(OBJ_DIR)
		@make -C $(LIB_DIR) clean
		@echo Cleaned object files

fclean: clean
		@/bin/rm -f $(NAME)
		@make -C $(LIB_DIR) fclean
		@echo Cleaned $(NAME)

re: fclean all

.PHONY: all clean flcean re