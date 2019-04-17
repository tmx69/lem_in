# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/19 19:47:23 by jritchie          #+#    #+#              #
#    Updated: 2019/04/16 18:03:28 by jritchie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LEM_IN = lem-in

LIB = libft/libftprintf.a

SRC_LEM_IN = ft_start.c \
			ft_del_link.c \
			ft_make_road.c \
			ft_make_rooms.c \
			ft_new_list.c \
			ft_print_paths.c \
			ft_solve.c \
			ft_utility.c \
			ft_lem_print.c

FLAGC = -Wall -Wextra -Werror

OBJ_LEM_IN = $(SRC_LEM_IN:%.c=%.o)

all: $(LIB) $(LEM_IN)

$(LIB):
	@make -C libft

$(LEM_IN): $(SRC_LEM_IN)
	@gcc -g $(FLAGC) -c $(SRC_LEM_IN)
	@gcc -g $(FLAGC) $(OBJ_LEM_IN) $(LIB) -o $(LEM_IN)

clean:
	@make clean -C libft
	@rm -f $(OBJ_LEM_IN)

fclean: clean
	@make fclean -C libft
	@rm -f $(LEM_IN)

re: fclean all
