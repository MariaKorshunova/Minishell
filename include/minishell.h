/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:53:33 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/21 20:39:23 by jmabel           ###   ########.fr       */
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
	int			exit_flag;
}	t_data;

/* ./utils/key_value_list_functions */
t_key_val	*lstnew_key_value(void *key, void *value);
t_key_val	*lstlast_key_value(t_key_val *lst);
void		lstadd_back_key_value(t_key_val **lst, t_key_val *new);
void		lstprint_key_value(t_key_val *lst);

/* ./utils/key_value_list_clear.c */
void		lstdelone_key_value(t_key_val *lst);
void		lstclear_key_value(t_key_val **lst);

#endif