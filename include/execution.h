/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 18:16:28 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/08 17:24:42 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "minishell.h"

typedef struct s_data		t_data;
typedef struct s_key_val	t_key_val;
typedef struct s_exec		t_exec;

/* child.c */
int			ft_child(t_data *data, t_exec **pipeline);

/* error_execution.c */
void		ft_print_error(char *name, char *str_error);
void		ft_close_pipefd(t_data *data, int *pipefd, int both);
void		ft_error_child_process(t_data *data, t_exec **pipeline);

/* exec_child.c */
void		ft_exec(t_data *data, t_exec **pipeline, t_exec *exec);

/* execution.c */
int			execution(t_data *data, char *prompt);

/* file_operations.c */
void		ft_close_file(int fd, char *name);
int			open_infile(t_data *data, char *infile);

/* heredoc.c */
int			ft_heredoc(t_data *data, t_key_val *infile);

/* redirect.c */
int			redicrect_infile(t_data *data, t_key_val *infile);

#endif