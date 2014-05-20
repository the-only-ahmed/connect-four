# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/25 02:16:49 by jyim              #+#    #+#              #
#    Updated: 2014/03/09 05:36:51 by ael-kadh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = puissance4

SRC = main.c alumin.c init.c verification.c inteligence.c check_move.c free.c\
		choose.c plus_check.c first_diag.c play.c

OBJ = $(SRC:.c=.o)

FLAGS = -g3 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@gcc $(OBJ) -L libft -lft libft/printf/libftprintf.a -o $(NAME)

%.o: %.c
	@gcc $(FLAGS) -c -I libft/includes -I libft/printf/includes $<

clean:
	@/bin/rm $(OBJ)
	@make -C libft/ clean

fclean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
