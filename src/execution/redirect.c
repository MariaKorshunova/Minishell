/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:19:22 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/10 13:15:58 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	redicrect_infile(t_data *data, t_key_val *infile)
{
	if (!infile)
		return (EXIT_SUCCESS);
	while (infile)
	{
		if (*(int *)infile->key == LESS)
		{
			if (open_infile(data, (char *)infile->value))
			{
				ft_print_error(infile->value, strerror(errno));
				return (EXIT_FAILURE);
			}
			if (infile->next)
				ft_close_file(data->infile_fd, (char *)infile->value);
		}
		else if (*(int *)infile->key == DOUBLE_LESS)
		{
			if (ft_heredoc(data, infile))
				return (EXIT_FAILURE);
		}
		infile = infile->next;
	}
	if (dup2(data->infile_fd, STDIN_FILENO) == -1)
	{
		perror(PREFIX_ERROR);
		ft_close_file(data->infile_fd, (char *)infile->value);
		return (EXIT_FAILURE);
	}
	// ft_close_file(data->infile_fd, NULL);
	return (EXIT_SUCCESS);
}
