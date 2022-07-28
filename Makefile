# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 16:43:04 by jmabel            #+#    #+#              #
#    Updated: 2022/07/25 19:22:05 by jmabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY		:	all clean fclean re libft

NAME		=	minishell

HEADER		=	$(addprefix include/,\
							minishell.h\
							parser.h)

CFLAGS		=	-I include

# CFLAGS		+=	-Wall -Wextra -Werror
CFLAGS		+=	-Wall -Wextra -Werror -fsanitize=address -g

LDFLAGS		=	-lreadline -L/Users/$(USER)/.brew/opt/readline/lib

RM			=	rm -rf

LIBFT		=	./libft/libft.a

FILE_C		=	main.c

FILE_C		+=	$(addprefix parser/,\
				pars_envp.c)

FILE_C		+=	$(addprefix utils/,\
				key_value_list_functions.c\
				key_value_lstclear.c\
				envp_list_to_chararray.c\
				array_operations.c\
				destructor.c)

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