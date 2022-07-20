/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:59:55 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/20 17:30:30 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

typedef struct s_data		t_data;
typedef struct s_key_value	t_key_value;

/* key_value_list_functions */
t_key_value	*lstnew_key_value(void *key, void *value);

/* pars_envp.c */
void		pars_envp(t_key_value *list_env, char **envp);
void		lstadd_back_key_value(t_key_value **lst, t_key_value *new);

#endif
