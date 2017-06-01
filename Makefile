# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/24 15:08:19 by ybelilov          #+#    #+#              #
#    Updated: 2017/03/24 15:08:20 by ybelilov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC =	main.c \
		check.c \
		hook.c \
		celtic_celtic_tricorn.c \
		heart_perpendicular_burning_ship.c \
		julia_mandelbrot.c \
		tricorn_burning_ship.c \

LIB = libft/libft.a

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -O3

MLX_F =  -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft/ re
	@make -C ./libft/ clean
	@clang $(FLAGS) $(MLX_F) $(LIB) $(OBJ) -o $(NAME)
	@echo "Compilation done!"

%.o: %.c
	@clang -c $(FLAGS) -o $@ $<

lldb:
	@clang -g $(FLAGS) $(MLX_F) $(LIB) $(SRC) -o debug
	@echo "Use 'debug' for lldb."

lclean:
	@rm -f debug
	@echo "'debug' removed!"

clean:
	@rm -f $(OBJ)
	@echo "Objects removed!"

fclean: clean
	@rm -f $(NAME)
	@echo "Executable removed!"

re: fclean all
