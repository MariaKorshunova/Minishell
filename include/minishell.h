/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:53:33 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/25 19:21:06 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h> 
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include "parser.h"

# define PROMPT "\e[1;32m minishell$ \e[0m"
# define PREFIX_ERROR	"minishell"

/* struct for list key-value */
typedef struct s_key_val
{
	void				*key;
	void				*value;
	struct s_key_val	*next;
}	t_key_val;

/* Struct with common var in minishell */
typedef struct s_data
{
	t_key_val	*env;
	char		**env_arr;
	int			exit_flag;
}	t_data;

/* .src//utils/key_value_list_functions */
t_key_val	*lstnew_key_value(void *key, void *value);
t_key_val	*lstlast_key_value(t_key_val *lst);
int			lst_size_key_value(t_key_val *lst);
void		lstadd_back_key_value(t_key_val **lst, t_key_val *new);
void		lstprint_key_value(t_key_val *lst);

/* .src//utils/key_value_list_clear.c */
void		lstdelone_key_value(t_key_val *lst);
void		lstclear_key_value(t_key_val **lst);

/* .src/utils/envp_list_to_chararray.c */
int			envp_list_to_chararray(t_data *data);

/* .src/utils/array_operations.c */
void		free_2dimensional_array(void **arr);
void		print_2dimensional_chararray(char **arr);

/* .src/utils/destructor.c */
void		destructor_minishell(t_data *data);

#endif