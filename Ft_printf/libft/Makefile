CC = gcc
FLAGS = -Wall -Werror -Wextra
NAME = libft.a
FT = *.c
OBJ = *.o

$(NAME):
	${CC} ${FLAGS} -c ${FT}
	ar rc ${NAME} ${OBJ}
	ranlib ${NAME}

all: 	$(NAME)

clean:
	rm -f ${OBJ}

fclean: 	clean
	rm -f ${NAME}

re: 	fclean all
