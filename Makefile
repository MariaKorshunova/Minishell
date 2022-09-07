# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: refrain <refrain@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 16:43:04 by jmabel            #+#    #+#              #
#    Updated: 2022/09/07 21:27:46 by refrain          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY		:	all clean fclean re libft

NAME		=	minishell

HEADER		=	$(addprefix include/,\
							minishell.h\
							parser.h\
							execution.h\
							builtins.h)

CFLAGS		=	-I include

CFLAGS		+=	-Wall -Wextra -Werror
# CFLAGS		+=	-fsanitize=address -g

LDFLAGS		=	-lreadline -L/Users/$(USER)/.brew/opt/readline/lib

RM			=	rm -rf

LIBFT		=	./libft/libft.a

LIBFT_H		= ./libft/libft.h

FILE_C		=	main.c

FILE_C		+=	$(addprefix parser/,\
				exec_fill.c\
				exec_lstclear.c\
				exec_lstcreate.c\
				exec_lstfunction.c\
				expand_dollar.c\
				pars_envp_lst.c\
				pars_envp.c\
				pars_pipeline.c\
				parser.c\
				lexer.c\
				lexer_spec_symbol_token.c\
				lexer_add_quote_token.c\
				lst_expand_dollar_spec_symbol.c\
				lst_expand_token.c\
				lst_token_operations.c\
				syntax_error.c)

FILE_C		+=	$(addprefix execution/,\
				child.c\
				error_execution.c\
				exec_child.c\
				execution.c\
				file_operations.c)

FILE_C		+=	$(addprefix utils/,\
				array_operations.c\
				envp_list_to_chararray.c\
				ft_strchr_pos.c\
				ft_strjoin_with_endchar.c\
				ft_strcmp.c\
				key_value_lstcreate.c\
				key_value_lstfunction.c\
				key_value_lstclear.c\
				key_value_search_with_key.c\
				lstfunction.c\
				destructor.c)

FILE_C		+=	$(addprefix builtins/,\
				find_builtin.c\
				ft_echo.c\
				ft_pwd.c\
				ft_cd.c\
				ft_env.c\
				ft_exit.c\
				builtin_utils.c)

FILE_C		+=	$(addprefix signals/,\
				signal.c)

SRCS		=	$(addprefix src/, $(FILE_C))

OBJ			=	$(addprefix objects/, $(FILE_C:%.c=%.o))

FOLDER		=	$(sort $(dir objects/ $(OBJ)))

all			:	$(FOLDER) libft $(NAME)

$(NAME)		:	$(OBJ) $(LIBFT)
				$(CC) $(LDFLAGS) $(CFLAGS) $(LIBFT) -L$(shell brew --prefix readline)/lib $(OBJ) -o $(NAME)

libft		:	libft_obj
				make -C ./libft

libft_obj	:
				mkdir libft_obj

$(FOLDER)	:
				mkdir -p $@

objects/%.o	:	./src/%.c $(HEADER) Makefile $(LIBFT_H)
				$(CC) $(CFLAGS) -I$(shell brew --prefix readline)/include -c $< -o $@

clean		:
				$(RM) $(OBJ)
				$(RM) $(FOLDER)
				make clean -C ./libft
				$(RM) libft_obj

fclean		:	clean
				$(RM) $(NAME)
				make fclean -C ./libft

re			:	fclean all