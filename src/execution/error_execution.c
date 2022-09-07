/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:18:09 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/07 18:08:43 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	ft_print_error(char *name, char *str_error)
{
	ft_putstr_fd(PREFIX_ERROR, 2);
	if (name)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(name, 2);
	}
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(str_error, 2);
	ft_putstr_fd("\n", 2);
}

void	ft_close_pipefd(t_data *data, int *pipefd, int both)
{
	if (both == 0)
	{
		ft_close_file(pipefd[0], NULL);
		ft_close_file(pipefd[1], NULL);
	}
	if (both == 1)
	{
		ft_close_file(data->pipe1[0], NULL);
		ft_close_file(data->pipe1[1], NULL);
		ft_close_file(data->pipe2[0], NULL);
		ft_close_file(data->pipe2[1], NULL);
	}
	perror (PREFIX_ERROR);
}
