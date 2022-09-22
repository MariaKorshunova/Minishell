/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:30:38 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/17 17:21:43 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	open_infile_less(t_data *data, char *infile)
{
	data->infile_fd = open(infile, O_RDONLY);
	if (data->infile_fd == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	open_outfile_greater(t_data *data, char *name)
{
	data->outfile_fd = open(name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (data->outfile_fd == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	open_outfile_doublegreater(t_data *data, char *name)
{
	data->outfile_fd = open(name, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (data->outfile_fd == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	init_file_flag(t_data *data)
{
	data->infile_flag = 0;
	data->outfile_flag = 0;
}
