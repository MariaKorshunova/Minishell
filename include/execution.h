/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 18:16:28 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/10 21:59:22 by jmabel           ###   ########.fr       */
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
void		ft_error_child_process(t_data *data, t_exec **pipeline);

/* exec_without_pipe.c */
int			execution_without_pipe(t_data *data, t_exec **pipeline,
				t_exec *exec);

/* exec.c */
void		ft_exec(t_data *data, t_exec **pipeline, t_exec *exec);

/* execution.c */
int			execution(t_data *data, char *prompt);

/* file_operations.c */
void		ft_close_file(int fd, char *name);
int			open_infile(t_data *data, char *infile);
int			open_outfile_greater(t_data *data, char *name);
int			open_outfile_doublegreater(t_data *data, char *name);

/* heredoc.c */
int			ft_heredoc(t_data *data, t_key_val *infile);

/* redirect.c */
int			redirect_infile(t_data *data, t_key_val *infile);
int			redirect_outfile(t_data *data, t_key_val *outfile);

#endif