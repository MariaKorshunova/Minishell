/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:30:38 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/07 18:50:31 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	ft_close_file(int fd, char *name)
{
	if (close(fd) == -1)
		ft_print_error(name, strerror(errno));
}

int	open_infile(t_data *data, char *infile)
{
	data->infile_fd = open(infile, O_RDONLY);
	if (data->infile_fd == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
