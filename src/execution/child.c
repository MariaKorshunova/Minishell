/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:26:38 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/09 01:05:30 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	ft_child_first(t_data *data, t_exec **pipeline, t_exec *exec);
static int	ft_child_first_childprocess(t_data *data, t_exec **pipeline,
				t_exec *exec);

int	ft_child(t_data *data, t_exec **pipeline)
{
	int	status;

	if (ft_child_first(data, pipeline, *pipeline))
		return (EXIT_FAILURE);
	wait(&status);
	return (EXIT_SUCCESS);
}

static int	ft_child_first(t_data *data, t_exec **pipeline, t_exec *exec)
{	
	if (find_builtin(exec->cmd, data))
		return (EXIT_SUCCESS);
	if (ft_child_first_childprocess(data, pipeline, exec))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	ft_child_first_childprocess(t_data *data, t_exec **pipeline,
				t_exec *exec)
{
	data->child = fork();
	if (data->child < 0)
	{
		ft_close_pipefd(data, data->pipe1, 0);
		return (EXIT_FAILURE);
	}
	else if (data->child == 0)
	{
		ft_close_file(data->pipe1[0], NULL);
		if (redicrect_infile(data, exec->infile))
		{
			// ft_close_file(data->pipe1[1], NULL);
			ft_error_child_process(data, pipeline);
		}
		ft_close_file(data->infile_fd, NULL);
		ft_close_file(data->pipe1[1], NULL);
		ft_exec(data, pipeline, exec);
	}
	return (EXIT_SUCCESS);
}
