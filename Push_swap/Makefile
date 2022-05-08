NAME		=	push_swap

CC			=	gcc
CFLAGS		=	-I. -Wall -Werror -Wextra
RM			=	@rm -f

HEADER		=	h_push_swap.h

ARG			:=	$(shell seq -100 2500 | sort -R | tail -n 500)

SRCS		=	srcs/push_swap.c \
				srcs/actions/pushreverse.c \
				srcs/actions/rotateswap.c \
				srcs/init_stack/no_rep.c \
				srcs/init_stack/getting_num.c \
				srcs/init_stack/atoi_modified.c \
				srcs/sorter/sorter.c \
				srcs/sorter/sorter_shortmed.c \
				srcs/sorter/sorter_chunks.c \
				srcs/sorter/chunks_algorithm/sorter_chunks_push.c \
				srcs/sorter/chunks_algorithm/sorter_chunks_push_aux.c \
				srcs/sorter/chunks_algorithm/sorter_chunks_back.c \
				srcs/sorter/chunks_algorithm/sorter_chunks_patcher.c 

OBJS		=	${SRCS:.c=.o}

$(NAME):		$(HEADER) $(OBJS)
				make -C libft
				${CC} ${OBJS} -I. -o $(NAME) -L. libft/libft.a

all:			${NAME}

clean:
				@${RM} ${OBJS}

fclean:			clean
				@${RM} ${NAME}
				@make -C libft fclean

re:
				@make fclean
				@make -C libft fclean
				@make all

random:            
				./push_swap $(ARG) | wc -l
test:            
				./push_swap $(ARG) | ./checker_Mac $(ARG)

.PHONY:			all clean fclean re
