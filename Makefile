# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 16:43:04 by jmabel            #+#    #+#              #
#    Updated: 2022/07/19 18:27:24 by jmabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

INCLUDES	=	include/
HEADER		=	$(addprefix include/,\
				minishell.h\
				parser.h)

CC			=	cc
CFLAGS		=	-I include
CFLAGS		+=	-Wall -Wextra -Werror
LDFLAGS		=	-lreadline -L/Users/$(USER)/.brew/opt/readline/lib

RM			=	rm -rf

LIBFT		=	./libft/libft.a

FILE_C		=	main.c
FILE_C		+=	$(addprefix parser/,\
				key_value_list_functions.c\
				pars_envp.c)

SRCS		=	$(addprefix src/, $(FILE_C))

OBJ			=	$(addprefix objects/, $(FILE_C:%.c=%.o))

FOLDER		=	$(sort $(dir objects/ $(OBJ)))

all			:	$(FOLDER) $(NAME)

$(NAME)		:	$(OBJ) $(LIBFT)
	$(CC) $(LDFLAGS) $(CFLAGS) $(LIBFT) $(OBJ) -o $(NAME)

$(LIBFT)	:
	make -C ./libft

$(FOLDER)	:
	mkdir -p $@

objects/%.o	:	./src/%.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -I $(INCLUDES) -c  $<  -o $@

.PHONY		:	all clean fclean re

clean		:
	$(RM) $(OBJ)
	$(RM) $(FOLDER)
	make clean -C ./libft

fclean		: clean
	$(RM) $(NAME)
	make fclean -C ./libft

re			:	fclean all