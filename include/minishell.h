/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:53:33 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/01 16:55:53 by jmabel           ###   ########.fr       */
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
# include "execution.h"

# define PROMPT "\e[1;32m minishell$ \e[0m"
# define PREFIX_ERROR	"minishell"
# define SPEC_SYMBOL "<>|'\""
# define SEPARATOR " \t"

typedef enum e_token_type
{
	SEP,
	WORD,
	GREATER,
	DOUBLE_GREATER,
	LESS,
	DOUBLE_LESS,
	QUOTE,
	DOUBLE_QUOTE,
	PIPE,
}	t_token_type;

/* struct for list key-value */
typedef struct s_key_val
{
	void				*key;
	void				*value;
	struct s_key_val	*next;
}	t_key_val;

/* struct for executor */
typedef struct s_exec
{
	char			**cmd;
	t_key_val		**infile;
	t_key_val		**outfile;
	struct s_exec	*next;
}	t_exec;

/* Struct with common var in minishell */
typedef struct s_data
{
	t_key_val	*env;
	char		**env_arr;
	int			exit_status;
	int			exit_flag;
}	t_data;

/* .src/utils/array_operations.c */
void		free_2dimensional_array(void **arr);
void		print_2dimensional_chararray(char **arr);

/* .src/utils/envp_list_to_chararray.c */
int			envp_list_to_chararray(t_data *data);

/* ft_strchr_pos.c */
int			ft_strchr_pos(char *s, int c);

/* .src/utils/key_value_lstcreate.c */
t_key_val	*lstnew_key_value(void *key, void *value);
void		lstadd_back_key_value(t_key_val **lst, t_key_val *new);
int			lstnew_add_back_intkey_value(t_key_val **lst, int key, void *value);

/* .src/utils/key_value_lstfunction.c */
t_key_val	*lstlast_key_value(t_key_val *lst);
int			lst_size_key_value(t_key_val *lst);
void		lstprint_key_value(t_key_val *lst, char type);

/* .src/utils/key_value_list_clear.c */
void		lstdelone_key_value(t_key_val *lst);
void		lstclear_key_value(t_key_val **lst);

/* .src/utils/destructor.c */
void		destructor_minishell(t_data *data);

/* .src/utils/lstprint.c */
void		lstprint(t_list *lst, char c);

#endif