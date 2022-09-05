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

static int	execution_pipe(t_data *data, t_exec *pipeline);
static int	ft_child(t_data *data, t_exec *pipeline);

int	execution(t_data *data, char *prompt)
{
	t_exec	*pipeline;

	pipeline = NULL;
	pipeline = parser(data, prompt);
	if (pipeline == NULL)
	{
		perror(PREFIX_ERROR);
		return (EXIT_FAILURE);
	}
	print_exec(pipeline);
	if (execution_pipe(data, pipeline))
	{
		lstclear_exec(&pipeline);
		return (EXIT_FAILURE);
	}
	lstclear_exec(&pipeline);
	return (EXIT_SUCCESS);
}

static int	execution_pipe(t_data *data, t_exec *pipeline)
{
	int	i;

	(void) data;
	(void) pipeline;
	if (pipe(data->pipe1) == -1)
	{
		perror(PREFIX_ERROR);
		return (EXIT_FAILURE);
	}
	i = ft_child(data, pipeline);
	return (EXIT_SUCCESS);
}

static int	ft_child(t_data *data, t_exec *pipeline)
{
	int	i;

	i = 0;
	ft_child_first(pipex, argv, envp);
	ft_manage_middle_child(pipex, argv, &i);
	if (i % 2 == 0)
		ft_child_last(pipex, argv, pipex->pipe1);
	else
		ft_child_last(pipex, argv, pipex->pipe2);
	return (i);
}
