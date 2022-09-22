/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 14:25:25 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/17 17:27:45 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	dup2_infile_stdin(t_data *data)
{
	if (dup2(data->infile_fd, STDIN_FILENO) == -1)
	{
		perror(PREFIX_ERROR);
		ft_close_files_with_check_flag(data);
		return (EXIT_FAILURE);
	}
	ft_close_file(data->infile_fd, NULL);
	if (data->infile_flag == 2)
		unlink(data->name_heredoc);
	return (EXIT_SUCCESS);
}

int	dup2_outfile_stdout(t_data *data)
{
	if (dup2(data->outfile_fd, STDOUT_FILENO) == -1)
	{
		perror(PREFIX_ERROR);
		ft_close_files_with_check_flag(data);
		return (EXIT_FAILURE);
	}
	ft_close_file(data->outfile_fd, NULL);
	return (EXIT_SUCCESS);
}
