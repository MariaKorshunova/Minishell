/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:26:38 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/21 15:08:05 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	ft_manage_middle_child(t_data *data, t_exec **pipeline,
				t_exec **pipeline_current, int len_exec);
static int	wait_childs(t_data *data, int len_exec);

int	ft_child(t_data *data, t_exec **pipeline, int len_exec)
{
	t_exec	*pipeline_current;

	pipeline_current = *pipeline;
	if (ft_child_first(data, pipeline, pipeline_current))
		return (EXIT_FAILURE);
	pipeline_current = pipeline_current->next;
	if (ft_manage_middle_child(data, pipeline, &pipeline_current, len_exec))
		return (EXIT_FAILURE);
	if (ft_child_last(data, pipeline, pipeline_current, len_exec))
		return (EXIT_FAILURE);
	if (len_exec % 2 == 0)
		close_pipe(data->pipe1);
	else
		close_pipe(data->pipe2);
	if (wait_childs(data, len_exec))
	// if (wait_childs(data, *pipeline))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	ft_manage_middle_child(t_data *data, t_exec **pipeline,
				t_exec **pipeline_current, int len_exec)
{
	int	i;

	i = 1;
	while (i < len_exec - 1)
	{
		init_file_flag(data);
		if (i % 2 == 1)
		{
			if (open_pipe(data->pipe2, data->pipe1))
				return (EXIT_FAILURE);
			ft_child_middle_odd(data, pipeline, *pipeline_current);
			close_pipe(data->pipe1);
		}
		else
		{
			if (open_pipe(data->pipe1, data->pipe2))
				return (EXIT_FAILURE);
			ft_child_middle_even(data, pipeline, *pipeline_current);
			close_pipe(data->pipe2);
		}
		*pipeline_current = (*pipeline_current)->next;
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	wait_childs(t_data *data, int len_exec)
{
	int	i;
	int	*status;

	i = 0;
	status = (int *)malloc((len_exec + 1) * sizeof(int));
	if (!status)
		return (EXIT_FAILURE);
	while (i < len_exec)
	{
		if (wait(&(status[i])) == -1)
		{
			free(status);
			return (EXIT_FAILURE);
		}
		i++;
	}
	data->exit_status = 0;
	while (i > 0)
	{
		if (WIFEXITED(status[i]) != 0)
			data->exit_status = WEXITSTATUS(status[i]);
		i--;
	}
	free(status);
	return (EXIT_SUCCESS);
}
