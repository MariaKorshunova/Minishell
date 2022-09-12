/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_without_pipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:57:31 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/12 15:38:42 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	tmp_stdin_stdout(int *tmp_stdin, int *tmp_stdout);
static int	redirect_without_pipe(t_data *data, t_exec *exec);
static int	child_without_pipe(t_data *data, t_exec **pipeline,
				t_exec *exec);
static int	return_origin_stdin_stdout(int tmp_stdin, int tmp_stdout);

int	execution_without_pipe(t_data *data, t_exec **pipeline,
				t_exec *exec)
{
	int	tmp_stdin;
	int	tmp_stdout;
	int	status_builtin;

	if (tmp_stdin_stdout(&tmp_stdin, &tmp_stdout))
		return (EXIT_FAILURE);
	if (redirect_without_pipe(data, exec))
		return (EXIT_FAILURE);
	status_builtin = find_builtin(exec->cmd, data);
	if (status_builtin == -1)
	{
		perror(PREFIX_ERROR);
		return (EXIT_FAILURE);
	}
	else if (status_builtin == 1)
	{
		if (return_origin_stdin_stdout(tmp_stdin, tmp_stdout))
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	if (child_without_pipe(data, pipeline, exec))
		return (EXIT_FAILURE);
	if (return_origin_stdin_stdout(tmp_stdin, tmp_stdout))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	tmp_stdin_stdout(int *tmp_stdin, int *tmp_stdout)
{
	*tmp_stdin = dup(0);
	*tmp_stdout = dup(1);
	if (*tmp_stdin == -1 || *tmp_stdout == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	redirect_without_pipe(t_data *data, t_exec *exec)
{
	if (open_infile_outfile(data, exec))
		return (EXIT_FAILURE);
	if (data->infile_flag == 1)
	{
		if (dup2_infile_stdin(data))
		{
			perror (PREFIX_ERROR);
			return (EXIT_FAILURE);
		}
	}
	if (data->outfile_flag == 1)
	{
		if (dup2_outfile_stdout(data))
		{
			perror (PREFIX_ERROR);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

static int	child_without_pipe(t_data *data, t_exec **pipeline,
				t_exec *exec)
{
	data->child = fork();
	if (data->child < 0)
		return (EXIT_FAILURE);
	else if (data->child == 0)
		ft_exec(data, pipeline, exec);
	wait(&(data->exit_status));
	return (EXIT_SUCCESS);
}

static int	return_origin_stdin_stdout(int tmp_stdin, int tmp_stdout)
{
	if (dup2(tmp_stdin, STDIN_FILENO) == -1)
	{
		perror (PREFIX_ERROR);
		return (EXIT_FAILURE);
	}
	if (dup2(tmp_stdout, STDOUT_FILENO) == -1)
	{
		perror (PREFIX_ERROR);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
