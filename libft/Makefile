# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jritchie <jritchie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/21 18:10:01 by jritchie          #+#    #+#              #
#    Updated: 2019/02/25 17:17:02 by jritchie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang
NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror -O2
LIBFT = libft
DIR_S = srcs
DIR_O = obj
HEADER = includes
SURCES = ft_printf.c \
ft_parsing_di.c \
ft_parsing_o.c \
ft_parsing_s.c \
ft_parsing_x.c \
ft_parsing_spec.c \
ft_parsing_pcper.c \
ft_parsing_u.c \
ft_parsing_f.c \
ft_float.c \
ft_floathash.c \
cast.c \

SRCS = $(addprefix $(DIR_S)/,$(SURCES))
OBJS = $(addprefix $(DIR_O)/,$(SURCES:.c=.o))
all: $(NAME)
$(NAME): $(OBJS)
		@make -C $(LIBFT)
		@cp libft/libft.a ./$(NAME)
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)
$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)/ft_printf.h
	@mkdir -p obj
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<
clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)
fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
re: fclean all
.PHONY: fclean re norme all clean