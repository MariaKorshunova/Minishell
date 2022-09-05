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

	pipeline = NULL;
	pipeline = parser(data, prompt);
	if (pipeline == NULL)
		return (EXIT_FAILURE);
	print_exec(pipeline);
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
	(void) data;
	(void) pipeline;
	if (pipe(data->pipe1) == -1)
	{
		perror(PREFIX_ERROR);
		return (EXIT_FAILURE);
	}
	if (ft_child(data, pipeline))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
