CC = gcc

FLAGS = -Werror -Wextra -Wall

NAME = libftprintf.a

SRC = 	*.c \
	ft_printf.h \
	./libft/*.c \
	./libft/libft.h \

OBJS = $(SRC:.c=*.o)


$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) *.o
	ranlib $(NAME)

all: $(NAME)

clean: 
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
