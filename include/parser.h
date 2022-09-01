/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:59:55 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/01 18:28:24 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

typedef struct s_data		t_data;
typedef struct s_key_val	t_key_val;
typedef struct s_exec		t_exec;

/* pars_envp.c */
int			pars_envp(t_data *data, char **envp);

/* parser.c */
t_list		*parser(t_data *data, char *prompt);

/* lexer.c */
t_key_val	*lexer(char *prompt);

/* lexer_spec_symbol_token.c */
int			add_less_token(t_key_val **token_list, char *prompt, int *i);
int			add_greater_token(t_key_val **token_list, char *prompt, int *i);
int			add_pipe_token(t_key_val **token_list, char *prompt, int *i);

/* lexer_add_quote_token.c */
int			add_quotes_token(t_key_val **token_list, char *prompt, int *i);

/* lst_expand_token.c */
t_list		*expand_tokens(t_key_val *token, t_data *data);

/* lst_token_operations.c */
int			add_note_lst_from_token(t_list **expand_token, char *value);
int			strdup_str_add_note_lst(t_list **expand_token, char *str);
int			substr_add_note_lst(t_list **expand_token, char *str,
				int start, int len);

/* open_quotes.c */
char		*open_quotes(t_key_val **token, t_data *data);

/* syntax_error.c */
int			check_syntax_error(t_key_val *token_list);

#endif
