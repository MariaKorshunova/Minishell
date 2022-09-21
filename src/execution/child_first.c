/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_first.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:18:54 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/21 14:59:52 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	ft_child_first_childprocess(t_data *data, t_exec **pipeline,
				t_exec *exec);
static void	redirect_child_first(t_data *data, t_exec **pipeline);

int	ft_child_first(t_data *data, t_exec **pipeline, t_exec *exec)
{	
	data->child = fork();
	if (data->child < 0)
	{
		ft_close_file(data->pipe1[0], NULL);
		ft_close_file(data->pipe1[1], NULL);
		return (EXIT_FAILURE);
	}
	else if (data->child == 0)
		ft_child_first_childprocess(data, pipeline, exec);
	exec->pid_child = data->child;
	return (EXIT_SUCCESS);
}

static void	ft_child_first_childprocess(t_data *data, t_exec **pipeline,
				t_exec *exec)
{
	int	status_builtin;

	data->outfile_fd = data->pipe1[1];
	ft_close_file(data->pipe1[0], NULL);
	if (open_infile_outfile(data, exec))
	{
		ft_close_file(data->pipe1[1], NULL);
		ft_error_child_process(data, pipeline);
	}
	redirect_child_first(data, pipeline);
	ft_close_file(data->pipe1[1], NULL);
	if (data->outfile_flag == 1)
		ft_close_file(data->outfile_fd, NULL);
	status_builtin = find_builtin(exec->cmd, data);
	if (status_builtin == -1)
	{
		perror(PREFIX_ERROR);
		ft_error_child_process(data, pipeline);
	}
	else if (status_builtin == 1)
		exit(data->exit_status);
	ft_exec(data, pipeline, exec);
}

static void	redirect_child_first(t_data *data, t_exec **pipeline)
{
	if (data->infile_flag > 0)
	{
		if (dup2_infile_stdin(data))
		{
			perror(PREFIX_ERROR);
			ft_close_file(data->pipe1[1], NULL);
			if (data->outfile_flag == 1)
				ft_close_file(data->outfile_fd, NULL);
			ft_error_child_process(data, pipeline);
		}
	}
	if (dup2(data->outfile_fd, STDOUT_FILENO) == -1)
	{
		perror(PREFIX_ERROR);
		if (data->infile_flag > 0)
			ft_close_file(data->infile_fd, NULL);
		if (data->infile_flag == 2)
			unlink(data->name_heredoc);
		if (data->outfile_flag == 1)
			ft_close_file(data->outfile_fd, NULL);
		ft_close_file(data->pipe1[1], NULL);
		ft_error_child_process(data, pipeline);
	}
}
