# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 16:43:04 by jmabel            #+#    #+#              #
#    Updated: 2022/07/12 19:36:31 by jmabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

HEADER		=	./include/minishell.h

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
LDFLAGS		=	-lreadline -L/Users/jmabel/.brew/opt/readline/lib

RM			=	rm -rf

SRCS		=	main.c

LIBFT		=	./libft/libft.a

OBJ			=	$(SRCS:%.c=%.o)

all			:	$(NAME)

$(NAME)		:	$(OBJ) $(LIBFT)
	$(CC) $(LDFLAGS) $(CFLAGS) $(LIBFT) $(OBJ) -o $(NAME)

$(LIBFT)	:
	make -C ./libft

%.o			:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c  $<  -o $@

.PHONY		:	all clean fclean re

clean		:
	$(RM) $(OBJ) $(OBJ_CHECKER)
	make clean -C ./libft

fclean		: clean
	$(RM) $(NAME) $(NAME_CHECKER)
	make fclean -C ./libft

re			:	fclean all