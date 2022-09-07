/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:26:38 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/07 18:53:13 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	ft_child_first(t_data *data, t_exec **pipeline);

int	ft_child(t_data *data, t_exec **pipeline)
{
	int	status;

	if (ft_child_first(data, pipeline))
		return (EXIT_FAILURE);
	wait(&status);
	return (EXIT_SUCCESS);
}

static int	ft_child_first(t_data *data, t_exec **pipeline)
{
	if (find_builtin((*pipeline)->cmd, data))
		return (EXIT_SUCCESS);
	data->child = fork();
	if (data->child < 0)
	{
		ft_close_pipefd(data, data->pipe1, 0);
		return (EXIT_FAILURE);
	}
	else if (data->child == 0)
	{
		ft_close_file(data->pipe1[0], NULL);
		if (redicrect_infile(data, (*pipeline)->infile))
		{
			ft_print_error((char *)(*pipeline)->infile->value, strerror(errno));
			ft_close_file(data->pipe1[1], NULL);
			destructor_minishell(data);
			lstclear_exec(pipeline);
			exit(errno);
		}
		ft_close_file(data->pipe1[1], NULL);
		ft_exec(data, pipeline);
	}
	return (EXIT_SUCCESS);
}
