/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:26:38 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/12 14:14:41 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	ft_child_first(t_data *data, t_exec **pipeline, t_exec *exec);
static void	ft_child_first_childprocess(t_data *data, t_exec **pipeline,
				t_exec *exec);
static int	ft_child_last_tmp(t_data *data, t_exec **pipeline, t_exec *exec);

int	ft_child(t_data *data, t_exec **pipeline)
{
	int		status1;
	int		status2;
	t_exec	*pipeline_current;

	pipeline_current = *pipeline;
	if (ft_child_first(data, pipeline, pipeline_current))
		return (EXIT_FAILURE);
	pipeline_current = pipeline_current->next;
	if (ft_child_last_tmp(data, pipeline, pipeline_current))
		return (EXIT_FAILURE);
	ft_close_file(data->pipe1[0], NULL);
	ft_close_file(data->pipe1[1], NULL);
	wait(&status1);
	wait(&status2);
	return (EXIT_SUCCESS);
}

static int	ft_child_first(t_data *data, t_exec **pipeline, t_exec *exec)
{	
	if (find_builtin(exec->cmd, data))
		return (EXIT_SUCCESS);
	data->child = fork();
	if (data->child < 0)
	{
		ft_close_file(data->pipe1[0], NULL);
		ft_close_file(data->pipe1[1], NULL);
		return (EXIT_FAILURE);
	}	
	else if (data->child == 0)
		ft_child_first_childprocess(data, pipeline, exec);
	return (EXIT_SUCCESS);
}

static void	ft_child_first_childprocess(t_data *data, t_exec **pipeline,
				t_exec *exec)
{
	data->outfile_fd = data->pipe1[1];
	ft_close_file(data->pipe1[0], NULL);
	if (open_infile(data, exec->infile))
	{
		ft_close_file(data->pipe1[1], NULL);
		ft_error_child_process(data, pipeline);
	}
	if (open_outfile(data, exec->outfile))
	{
		ft_close_file(data->pipe1[1], NULL);
		if (data->infile_flag == 1)
			ft_close_file(data->infile_fd, NULL);
		ft_error_child_process(data, pipeline);
	}
	if (dup2(data->outfile_fd, STDOUT_FILENO) == -1)
	{
		ft_close_file(data->infile_fd, NULL);
		ft_close_file(data->pipe1[1], NULL);
		ft_error_child_process(data, pipeline);
	}
	ft_close_file(data->infile_fd, NULL);
	ft_close_file(data->pipe1[1], NULL);
	ft_exec(data, pipeline, exec);
}

static int	ft_child_last_tmp(t_data *data, t_exec **pipeline, t_exec *exec)
{
	data->child = fork();
	if (data->child == 0)
	{
		data->infile_fd = data->pipe1[0];
		ft_close_file(data->pipe1[1], NULL);
		// if (redirect_infile(data, exec->infile))
		// {
		// 	ft_close_file(data->pipe1[1], NULL);
		// 	ft_error_child_process(data, pipeline);
		// }
		dup2(data->infile_fd, STDIN_FILENO);
		// ft_close_file(data->infile_fd, NULL);
		ft_close_file(data->infile_fd, NULL);
		ft_exec(data, pipeline, exec);
	}
	return (EXIT_SUCCESS);
}
