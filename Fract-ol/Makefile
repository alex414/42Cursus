# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/19 18:17:58 by adiaz-do          #+#    #+#              #
#    Updated: 2021/06/20 15:47:25 by adiaz-do         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

FLAG = -Wall -Werror -Wextra -O3

SRC = fractol.c fractals.c mlx_manager.c draw.c color.c events.c mouse.c 

INCLUDE = ./includes

SRO = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRO)
	make -C ./libft/
	$(CC) $(FLAG) -I$(INCLUDE) $(SRC) -lmlx -framework OpenGL -framework Appkit ./libft/libft.a -o $(NAME)

%.o: %.c ./includes/fractol.h
	$(CC) $(FLAG) -c -o $@ $<

clean:
	make -C libft/ clean
	rm -f $(SRO)

fclean: clean
	make -C libft/ fclean
	rm -Rf $(NAME)

re: fclean all
	