# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adiaz-do <adiaz-do@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/08 12:08:37 by adiaz-do          #+#    #+#              #
#    Updated: 2021/05/06 14:24:27 by adiaz-do         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = ft_isprint.c ft_memset.c ft_strncmp.c ft_putstr_fd.c ft_putchar_fd.c ft_substr.c ft_putnbr_fd.c ft_putendl_fd.c ft_wordlen.c ft_wordcount.c ft_atoi.c ft_strnew.c ft_isspace.c ft_strnstr.c ft_bzero.c ft_memalloc.c ft_strchr.c ft_strrchr.c ft_calloc.c ft_memccpy.c ft_strcmp.c ft_tolower.c ft_isalnum.c ft_memchr.c ft_strdup.c ft_toupper.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_isalpha.c ft_memcmp.c ft_isascii.c ft_memcpy.c ft_strlcpy.c ft_isdigit.c ft_memmove.c ft_strlen.c

SRCS_B  = ft_lstadd_back_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c	ft_lstsize_bonus.c ft_lstadd_front_bonus.c ft_lstdelone_bonus.c ft_lstlast_bonus.c

OBJS	= ${SRCS:.c=.o}

OBJS_B	= ${SRCS_B:.c=.o}

CC		= cc

RM		= rm -f

NAME	= libft.a

CFLAGS	= -Wall -Werror -Wextra

${NAME}:	
			$(CC) $(CFLAGS) -c $(SRCS) 
			ar rc $(NAME) $(OBJS) 
			ranlib $(NAME)
bonus:
			$(CC) $(CFLAGS) -c $(SRCS_B)
			ar rc $(NAME) $(OBJS_B)
			ranlib $(NAME)

all:	$(NAME)

clean:
			$(RM) $(OBJS) $(OBJS_B)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re
