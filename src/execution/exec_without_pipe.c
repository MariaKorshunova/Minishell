/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_without_pipe.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:57:31 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/10 22:23:40 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	redirect_without_pipe(t_data *data, t_exec *exec);
static int	dup2_infile_stdin(t_data *data);
static int	dup2_outfile_stdout(t_data *data);

int	execution_without_pipe(t_data *data, t_exec **pipeline,
				t_exec *exec)
{
	if (find_builtin(exec->cmd, data))
		return (EXIT_SUCCESS);
	data->child = fork();
	if (data->child < 0)
		return (EXIT_FAILURE);
	else if (data->child == 0)
	{
		if (redirect_without_pipe(data, exec))
			ft_error_child_process(data, pipeline);
		if (data->infile_flag == 1)
			dup2_infile_stdin(data);
		if (data->outfile_flag == 1)
			dup2_outfile_stdout(data);
		ft_exec(data, pipeline, exec);
	}
	else
		wait(&(data->exit_status));
	return (EXIT_SUCCESS);
}

static int	redirect_without_pipe(t_data *data, t_exec *exec)
{
	if (redirect_infile(data, exec->infile))
		return (EXIT_FAILURE);
	if (redirect_outfile(data, exec->outfile))
	{
		if (data->infile_flag == 1)
			ft_close_file(data->infile_fd, NULL);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	dup2_infile_stdin(t_data *data)
{
	if (dup2(data->infile_fd, STDIN_FILENO) == -1)
	{
		perror(PREFIX_ERROR);
		ft_close_file(data->infile_fd, NULL);
		if (data->outfile_flag == 1)
			ft_close_file(data->outfile_fd, NULL);
		return (EXIT_FAILURE);
	}
	ft_close_file(data->infile_fd, NULL);
	return (EXIT_SUCCESS);
}

static int	dup2_outfile_stdout(t_data *data)
{
	if (dup2(data->outfile_fd, STDOUT_FILENO) == -1)
	{
		perror(PREFIX_ERROR);
		if (data->infile_flag == 1)
			ft_close_file(data->infile_fd, NULL);
		ft_close_file(data->outfile_fd, NULL);
		return (EXIT_FAILURE);
	}
	ft_close_file(data->outfile_fd, NULL);
	return (EXIT_SUCCESS);
}
