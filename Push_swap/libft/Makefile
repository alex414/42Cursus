# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/08 12:08:37 by adiaz-do          #+#    #+#              #
#    Updated: 2021/11/01 21:15:40 by adiaz-do         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = ft_isprint.c ft_itoa.c ft_memset.c ft_strncmp.c ft_putstr_fd.c ft_putchar_fd.c ft_substr.c ft_putnbr_fd.c ft_putendl_fd.c ft_wordlen.c ft_wordcount.c ft_atoi.c ft_strnew.c ft_isspace.c ft_strnstr.c ft_bzero.c ft_memalloc.c ft_strchr.c ft_strrchr.c ft_calloc.c ft_memccpy.c ft_strcmp.c ft_tolower.c ft_isalnum.c ft_memchr.c ft_strdup.c ft_toupper.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_isalpha.c ft_memcmp.c ft_isascii.c ft_memcpy.c ft_strlcpy.c ft_isdigit.c ft_memmove.c ft_strlen.c ft_lstadd_back.c ft_lstclear.c ft_lstiter.c	ft_lstsize.c ft_lstadd_front.c ft_lstdelone.c ft_lstlast.c ft_lstnew.c ft_split.c

OBJS	= ${SRCS:.c=.o}

CC		= cc

RM		= rm -f

NAME	= libft.a

CFLAGS	= -Wall -Werror -Wextra

${NAME}:	
			$(CC) $(CFLAGS) -c $(SRCS) 
			ar rc $(NAME) $(OBJS) 
			ranlib $(NAME)

all:	$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re
