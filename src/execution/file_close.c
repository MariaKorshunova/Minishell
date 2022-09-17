/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:20:54 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/17 17:23:09 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	ft_close_file(int fd, char *name)
{
	if (close(fd) == -1)
		ft_print_error(name, strerror(errno));
}

void	ft_close_files_with_check_flag(t_data *data)
{
	if (data->infile_flag > 0)
		ft_close_file(data->infile_fd, NULL);
	if (data->infile_flag == 2)
		unlink(data->name_heredoc);
	if (data->outfile_flag == 1)
		ft_close_file(data->outfile_fd, NULL);
}
