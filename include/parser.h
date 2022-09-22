/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:59:55 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/21 13:55:23 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "minishell.h"

typedef struct s_data		t_data;
typedef struct s_key_val	t_key_val;
typedef struct s_exec		t_exec;

/* change_init_env.c */
int			change_init_env(t_key_val **env);

/* exec_fill.c */
int			fill_exec_by_condition(t_data *data, t_key_val **token,
				t_exec *note, t_list **cmd);

/* exec_lstclear.c */
void		lstdelone_exec(t_exec *lst);
void		lstclear_exec(t_exec **lst);

/* exec_lstcreate.c  */
t_exec		*lstnew_exec(char **cmd, t_key_val *infile, t_key_val *outfile);
void		lstadd_back_exec(t_exec **lst, t_exec *new);

/* exec_lstfunction.c */
t_exec		*lstlast_exec(t_exec *lst);
int			lst_size_exec(t_exec *lst);
void		print_exec(t_exec *exec);

/* expand_dollar.c */
char		*expand_dollar(t_key_val **token, t_data *data);

/* lexer.c */
t_key_val	*lexer(char *prompt);

/* lexer_spec_symbol_token.c */
int			add_less_token(t_key_val **token_list, char *prompt, int *i);
int			add_greater_token(t_key_val **token_list, char *prompt, int *i);
int			add_pipe_token(t_key_val **token_list, char *prompt, int *i);

/* lexer_add_quote_token.c */
int			add_quotes_token(t_key_val **token_list, char *prompt, int *i);

/* lst_expand_dollar_spec_symbol.c */
int			add_note_dollar_spec_symbol(char *str, t_list **expand_token,
				t_data *data, int *i);

/* lst_expand_token.c */
t_list		*expand_tokens(t_key_val **token, t_data *data);

/* lst_token_operations.c */
int			add_note_lst_from_token(t_list **expand_token, char *value);
int			strdup_str_add_note_lst(t_list **expand_token, char *str);
int			substr_add_note_lst(t_list **expand_token, char *str,
				int start, int len);
int			lst_sum_len_content(t_list *lst);

/* pars_envp_lst.c  */
int			pars_envp_lst(t_key_val **lst, char **envp);
int			add_lst_env(t_key_val **lst, char *str, int j);
char		*pars_name_envp(char *str, int j, t_key_val	**lst);
char		*pars_value_envp(char *str, int j, t_key_val **lst, char *name);

/* pars_envp.c */
int			pars_envp(t_data *data, char **envp);
int			ft_get_path(t_data *data);

/* pars_pipeline.c */
t_exec		*pipeline(t_data *data, t_key_val *token);

/* parser.c */
int			parser(t_data *data, char *prompt, t_exec **exec);

/* syntax_error.c */
int			check_syntax_error(t_key_val *token_list);

#endif
