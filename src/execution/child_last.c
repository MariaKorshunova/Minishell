/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_last.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:53:30 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/22 07:18:55 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	ft_child_last_childprocess(t_data *data, t_exec **pipeline,
				t_exec *exec, int *pipefd);
static void	redirect_child_last(t_data *data, t_exec **pipeline, int *pipefd);

int	ft_child_last(t_data *data, t_exec **pipeline, t_exec *exec, int len_exec)
{
	int	*pipefd;

	init_file_flag(data);
	if (len_exec % 2 == 0)
		pipefd = data->pipe1;
	else
		pipefd = data->pipe2;
	data->child = fork();
	if (data->child < 0)
	{
		ft_close_file(pipefd[0], NULL);
		ft_close_file(pipefd[1], NULL);
		return (EXIT_FAILURE);
	}
	if (data->child == 0)
		ft_child_last_childprocess(data, pipeline, exec, pipefd);
	data->last_pid = data->child;
	return (EXIT_SUCCESS);
}

static void	ft_child_last_childprocess(t_data *data, t_exec **pipeline,
				t_exec *exec, int *pipefd)
{
	int	status_builtin;

	data->infile_fd = pipefd[0];
	ft_close_file(pipefd[1], NULL);
	if (open_infile_outfile(data, exec))
	{
		ft_close_file(pipefd[0], NULL);
		ft_error_child_process(data, pipeline);
	}
	redirect_child_last(data, pipeline, pipefd);
	ft_close_file(pipefd[0], NULL);
	if (data->infile_flag > 0)
		ft_close_file(data->infile_fd, NULL);
	if (data->infile_flag == 2)
		unlink(data->name_heredoc);
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

static void	redirect_child_last(t_data *data, t_exec **pipeline, int *pipefd)
{
	if (dup2(data->infile_fd, STDIN_FILENO) == -1)
	{
		perror(PREFIX_ERROR);
		ft_close_files_with_check_flag(data);
		ft_close_file(pipefd[0], NULL);
		ft_error_child_process(data, pipeline);
	}
	if (data->outfile_flag == 1)
	{
		if (dup2_outfile_stdout(data))
		{
			perror (PREFIX_ERROR);
			ft_close_file(pipefd[0], NULL);
			ft_close_files_with_check_flag(data);
			ft_error_child_process(data, pipeline);
		}
	}
}
