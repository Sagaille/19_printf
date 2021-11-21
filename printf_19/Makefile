# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldavids <ldavids@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 14:16:48 by ldavids           #+#    #+#              #
#    Updated: 2020/02/12 14:35:08 by ldavids          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCLUDE = ./general2.h

LIBFT_ROOT = ./libft

PATH_SRC = ./

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = conversion01.c flags_int.c fonction_annexe.c fonctions_types.c intzero.c precision.c\
 strwidth.c width.c display_int.c flags_str.c fonction_conditions.c intern_case2.c proto3.c\
 

OBJ = $(SRCS:.c=.o)

all:	libft_all $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	    ar rc $(NAME) $(OBJ)

clean:
	    /bin/rm -f $(OBJ)
fclean: clean
	    /bin/rm -f $(NAME)
re:	fclean all

libft_all:
	$(MAKE) -C $(LIBFT_ROOT) all

libft_bonus:
	$(MAKE) -C $(LIBFT_ROOT) bonus

libft_clean:
	$(MAKE) -C $(LIBFT_ROOT) clean

libft_fclean:
	$(MAKE) -C $(LIBFT_ROOT) fclean