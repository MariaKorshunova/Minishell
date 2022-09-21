/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:08:34 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/29 18:15:39 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	execution_pipe(t_data *data, t_exec **pipeline);

int	execution(t_data *data, char *prompt)
{
	t_exec	*pipeline;
	int		parser_status;

	if (ft_strlen(prompt) == 0)
		return (EXIT_SUCCESS);
	add_history(prompt);
	if (envp_list_to_chararray(data))
		return (EXIT_FAILURE);
	free_2dimensional_array((void **)data->bin_path);
	// if (ft_get_path(data))
	// 	return (EXIT_FAILURE);
	pipeline = NULL;
	parser_status = parser(data, prompt, &pipeline);
	if (parser_status == -1)
		return (EXIT_FAILURE);
	if (parser_status == 1)
		return (EXIT_SUCCESS);
	if (execution_pipe(data, &pipeline))
	{
		lstclear_exec(&pipeline);
		return (EXIT_FAILURE);
	}
	lstclear_exec(&pipeline);
	return (EXIT_SUCCESS);
}

static int	execution_pipe(t_data *data, t_exec **pipeline)
{
	int	len_exec;

	init_file_flag(data);
	len_exec = lst_size_exec(*pipeline);
	if (len_exec == 1)
	{
		if (execution_without_pipe(data, pipeline, *pipeline))
			return (EXIT_FAILURE);
	}
	else
	{
		if (pipe(data->pipe1) == -1)
		{
			perror(PREFIX_ERROR);
			return (EXIT_FAILURE);
		}
		if (ft_child(data, pipeline, len_exec))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
