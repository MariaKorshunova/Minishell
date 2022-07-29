/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:59:55 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/29 15:45:41 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

typedef struct s_data		t_data;
typedef struct s_key_val	t_key_val;

/* pars_envp.c */
int			pars_envp(t_data *data, char **envp);

/* lexer_parser.c */
int			lexer_parser(t_data *data, char *prompt);

/* lexer.c */
t_key_val	*lexer(char *prompt);

/* lexer_spec_symbol_token.c */
int			add_less_token(t_key_val **token_list, char *prompt, int *i);
int			add_greater_token(t_key_val **token_list, char *prompt, int *i);
int			add_pipe_token(t_key_val **token_list, char *prompt, int *i);

/* lexer_add_quote_token.c */
int			add_quotes_token(t_key_val **token_list, char *prompt, int *i);

#endif
