/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_middle_odd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:29:33 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/22 07:19:12 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	ft_child_middle_childprocess_odd(t_data *data, t_exec **pipeline,
				t_exec *exec);
static void	define_child_infile_outfile_odd(t_data *data);
static void	redirect_child_middle_odd(t_data *data, t_exec **pipeline);

int	ft_child_middle_odd(t_data *data, t_exec **pipeline, t_exec *exec)
{
	data->child = fork();
	if (data->child < 0)
	{
		ft_close_file(data->pipe1[0], NULL);
		ft_close_file(data->pipe1[1], NULL);
		return (EXIT_FAILURE);
	}
	else if (data->child == 0)
		ft_child_middle_childprocess_odd(data, pipeline, exec);
	return (EXIT_SUCCESS);
}

static void	ft_child_middle_childprocess_odd(t_data *data, t_exec **pipeline,
				t_exec *exec)
{
	int	status_builtin;

	define_child_infile_outfile_odd(data);
	if (open_infile_outfile(data, exec))
	{
		ft_close_file(data->pipe1[0], NULL);
		ft_close_file(data->pipe2[1], NULL);
		ft_error_child_process(data, pipeline);
	}
	redirect_child_middle_odd(data, pipeline);
	ft_close_file(data->pipe1[0], NULL);
	ft_close_file(data->pipe2[1], NULL);
	ft_close_files_with_check_flag(data);
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

static void	define_child_infile_outfile_odd(t_data *data)
{
	data->infile_fd = data->pipe1[0];
	data->outfile_fd = data->pipe2[1];
	ft_close_file(data->pipe1[1], NULL);
	ft_close_file(data->pipe2[0], NULL);
}

static void	redirect_child_middle_odd(t_data *data, t_exec **pipeline)
{
	if (dup2(data->infile_fd, STDIN_FILENO) == -1)
	{
		perror(PREFIX_ERROR);
		ft_close_files_with_check_flag(data);
		ft_close_file(data->pipe1[0], NULL);
		ft_close_file(data->pipe2[1], NULL);
		ft_error_child_process(data, pipeline);
	}
	if (dup2(data->outfile_fd, STDOUT_FILENO) == -1)
	{
		perror(PREFIX_ERROR);
		ft_close_files_with_check_flag(data);
		ft_close_file(data->pipe1[0], NULL);
		ft_close_file(data->pipe2[1], NULL);
		ft_error_child_process(data, pipeline);
	}
}
