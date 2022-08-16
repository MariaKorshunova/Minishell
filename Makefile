# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 16:43:04 by jmabel            #+#    #+#              #
#    Updated: 2022/08/01 12:45:29 by jmabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY		:	all clean fclean re libft

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
				lexer.c\
				lexer_spec_symbol_token.c\
				lexer_add_quote_token.c\
				syntax_error.c)

FILE_C		+=	$(addprefix execution/,\
				execution.c)

FILE_C		+=	$(addprefix utils/,\
				key_value_lstcreate.c\
				key_value_lstfunction.c\
				key_value_lstclear.c\
				envp_list_to_chararray.c\
				array_operations.c\
				destructor.c)

FILE_C		+=	$(addprefix history/,\
				history.c)

FILE_C		+=	$(addprefix executor/,\
				executor.c)

SRCS		=	$(addprefix src/, $(FILE_C))

OBJ			=	$(addprefix objects/, $(FILE_C:%.c=%.o))

FOLDER		=	$(sort $(dir objects/ $(OBJ)))

all			:	$(FOLDER) libft $(NAME)

$(NAME)		:	$(OBJ)
				$(CC) $(LDFLAGS) $(CFLAGS) $(LIBFT) $(OBJ) -o $(NAME)

libft		:	libft_obj
				make -C ./libft

libft_obj	:
				mkdir libft_obj

$(FOLDER)	:
				mkdir -p $@

objects/%.o	:	./src/%.c $(HEADER) Makefile $(LIBFT)
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