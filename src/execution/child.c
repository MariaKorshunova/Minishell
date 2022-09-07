/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:26:38 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/05 21:35:27 by jmabel           ###   ########.fr       */
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
	data->child = fork();
	if (data->child < 0)
	{
		ft_error_fork(data, data->pipe1, 0);
		return (EXIT_FAILURE);
	}
	else if (data->child == 0)
	{
		ft_close_file(data->pipe1[0], NULL);
		ft_close_file(data->pipe1[1], NULL);
		ft_exec(data, pipeline);
	}
	return (EXIT_SUCCESS);
}

/*
		ft_close_file(pipex->pipe1[0], NULL);
		ft_open_infile(pipex, argv);
		if (pipex->infile_fd == -1)
			ft_error_open_file(pipex, pipex->pipe1[1]);
		if (dup2(pipex->infile_fd, STDIN_FILENO) == -1)
		{
			ft_close_file(pipex->infile_fd, argv[1]);
			ft_close_file(pipex->pipe1[1], NULL);
			ft_error_dup(pipex);
		}
		if (dup2(pipex->pipe1[1], STDOUT_FILENO) == -1)
		{
			ft_close_file(pipex->infile_fd, argv[1]);
			ft_close_file(pipex->pipe1[1], NULL);
			ft_error_dup(pipex);
		}
		ft_close_file(pipex->infile_fd, argv[1]);
		ft_close_file(pipex->pipe1[1], NULL);
		ft_exec(pipex, argv[2], envp);
*/