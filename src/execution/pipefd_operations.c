/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipefd_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:41:40 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/13 21:42:10 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	open_pipe(int *pipe_for_open, int *pipe_opened)
{
	if (pipe(pipe_for_open) == -1)
	{
		ft_close_file(pipe_opened[0], NULL);
		ft_close_file(pipe_opened[1], NULL);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	close_pipe(int *pipefd)
{
	ft_close_file(pipefd[0], NULL);
	ft_close_file(pipefd[1], NULL);
}
