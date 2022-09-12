/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:26:38 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/12 20:59:00 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	ft_child(t_data *data, t_exec **pipeline)
{
	int		status[2];
	int		i;
	t_exec	*pipeline_current;

	i = 0;
	pipeline_current = *pipeline;
	if (ft_child_first(data, pipeline, pipeline_current))
		return (EXIT_FAILURE);
	pipeline_current = pipeline_current->next;
	if (ft_child_last(data, pipeline, pipeline_current, data->pipe1))
		return (EXIT_FAILURE);
	ft_close_file(data->pipe1[0], NULL);
	ft_close_file(data->pipe1[1], NULL);
	wait(&(status[1]));
	wait(&(status[0]));
	data->exit_status = status[0] % 255;
	return (EXIT_SUCCESS);
}
