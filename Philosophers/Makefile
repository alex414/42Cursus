# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/03 18:35:26 by adiaz-do          #+#    #+#              #
#    Updated: 2022/04/04 19:18:42 by adiaz-do         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/cr_philos.c srcs/destroy.c srcs/init.c srcs/philo.c srcs/printaparse.c srcs/time.c srcs/utils.c
OBJS = $(SRCS:%.c=%.o)
NAME = philo
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM =	rm -rf

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -pthread $(OBJS) -o $(NAME)

$(%.o): $(%.c)
		$(CC) -c $^ -o $@

clean:
		$(RM) $(OBJS)
		@clear

fclean:
		make clean
		$(RM) $(NAME)
		@clear

re:
	make fclean all

.PHONY: clean fclean all re
