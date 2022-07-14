# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 16:09:09 by jmabel            #+#    #+#              #
#    Updated: 2022/07/14 17:28:28 by jmabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

SRCS		=	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	ft_isascii.c\
				ft_isprint.c	ft_strlen.c		ft_memset.c		ft_bzero.c\
				ft_memcpy.c		ft_memmove.c	ft_strlcpy.c	ft_strlcat.c\
				ft_toupper.c	ft_tolower.c	ft_strchr.c		ft_strrchr.c\
				ft_strncmp.c	ft_memchr.c		ft_memcmp.c		ft_strnstr.c\
				ft_atoi.c		ft_calloc.c		ft_strdup.c		ft_substr.c\
				ft_strjoin.c	ft_strtrim.c	ft_putchar_fd.c	ft_putstr_fd.c\
				ft_putendl_fd.c	ft_putnbr_fd.c	ft_itoa.c		ft_split.c\
				ft_striteri.c	ft_strmapi.c\
				ft_lstnew.c			ft_lstadd_front.c\
				ft_lstsize.c		ft_lstlast.c\
				ft_lstadd_back.c	ft_lstdelone.c\
				ft_lstclear.c		ft_lstiter.c\
				ft_lstmap.c

HEADER		=	libft.h

OBJ 		= 	$(SRCS:%.c=%.o)
RM 			= 	rm -rf
CC 			= 	cc 
CFLAGS 		= 	-Wall -Wextra -Werror

.PHONY		:	all clean fclean re bonus

all			:	$(NAME)

$(NAME)		:	$(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o			: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean 		:
	$(RM) $(OBJ)

fclean		: clean
	$(RM) $(NAME)

re			: fclean all