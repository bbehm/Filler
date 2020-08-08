# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbehm <bbehm@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 15:45:47 by bbehm             #+#    #+#              #
#    Updated: 2020/08/08 15:54:20 by bbehm            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strdup.c ft_strlen.c ft_atoi.c \
	  ft_strcpy.c ft_strncpy.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c \
	  ft_strncmp.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_putnbr.c \
	  ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memcpy.c ft_memset.c \
	  ft_bzero.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_putendl.c ft_putchar_fd.c \
	  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_memcmp.c ft_strcat.c \
	  ft_strncat.c ft_strlcat.c ft_itoa.c ft_memalloc.c ft_memdel.c ft_strnew.c \
	  ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strequ.c ft_strnequ.c \
	  ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_strmap.c ft_strmapi.c \
	  ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
	  ft_strleni.c ft_isupper.c ft_islower.c ft_isspace.c ft_intlen.c ft_strndup.c \
	  ft_itoa_base.c ft_putnbrmax_fd.c ft_put_zeros.c ft_ftoa.c ft_put_spaces.c \
	  ft_putnbr_size.c ft_putchar_size.c ft_itoa_base_size.c \
	  ft_putstr_size.c ft_put_plus.c ft_put_space.c ft_itoa_base_ul.c \
	  ft_intlen_u.c ft_putnbr_u.c get_next_line.c ft_printf.c \
	  do_the_d.c do_the_u.c do_the_o.c do_the_x.c do_the_f.c do_the_s.c \
	  do_the_c.c do_the_p.c fix_length.c fix_width.c fix_precision.c initialize.c \
	  parse.c percent_flag.c \

OBJ = $(SRC:%.c=%.o)
	  

HEADERS = includes/libft.h
FLAGS = -Wall -Werror -Wextra -c

$(NAME): all

all:
	gcc $(FLAGS) $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
