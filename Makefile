# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 16:43:04 by jmabel            #+#    #+#              #
#    Updated: 2022/09/01 13:02:22 by jmabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY		:	all clean fclean re

NAME		=	minishell

HEADER		=	$(addprefix include/,\
							minishell.h\
							parser.h\
							execution.h)

CFLAGS		=	-I include

CFLAGS		+=	-Wall -Wextra -Werror
CFLAGS		+=	-fsanitize=address -g

LDFLAGS		=	-lreadline -L/Users/$(USER)/.brew/opt/readline/lib

RM			=	rm -rf

LIBFT		=	./libft/libft.a

FILE_C		=	main.c

FILE_C		+=	$(addprefix parser/,\
				pars_envp.c\
				parser.c\
				lexer.c\
				lexer_spec_symbol_token.c\
				lexer_add_quote_token.c\
				open_quotes.c\
				syntax_error.c)

FILE_C		+=	$(addprefix execution/,\
				execution.c)

FILE_C		+=	$(addprefix utils/,\
				array_operations.c\
				envp_list_to_chararray.c\
				key_value_lstcreate.c\
				key_value_lstfunction.c\
				key_value_lstclear.c\
				lstprint.c\
				destructor.c)

SRCS		=	$(addprefix src/, $(FILE_C))

OBJ			=	$(addprefix objects/, $(FILE_C:%.c=%.o))

FOLDER		=	$(sort $(dir objects/ $(OBJ)))

all			:	$(FOLDER) $(NAME)

$(NAME)		:	$(OBJ) $(LIBFT)
				$(CC) $(LDFLAGS) $(CFLAGS) $(LIBFT) $(OBJ) -o $(NAME)

$(LIBFT)	:	libft_obj ./libft/Makefile
				make -C ./libft

libft_obj	:
				mkdir libft_obj

$(FOLDER)	:
				mkdir -p $@

objects/%.o	:	./src/%.c $(HEADER) Makefile ./libft/Makefile
				$(CC) $(CFLAGS) -c $< -o $@

clean		:
				$(RM) $(OBJ)
				$(RM) $(FOLDER)
				make clean -C ./libft
				$(RM) libft_obj

fclean		:	clean
				$(RM) $(NAME)
				make fclean -C ./libft

re			:	fclean all