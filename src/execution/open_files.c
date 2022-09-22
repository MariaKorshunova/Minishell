/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:19:22 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/21 13:06:15 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	open_infile_bypass(t_data *data, t_key_val *infile);
static int	open_outfile_bypass(t_data *data, t_key_val *outfile);

int	open_infile(t_data *data, t_key_val *infile)
{
	if (!infile)
		return (EXIT_SUCCESS);
	data->infile_flag = 1;
	if (open_infile_bypass(data, infile))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	open_infile_bypass(t_data *data, t_key_val *infile)
{
	while (infile)
	{
		if (open_infile_less(data, (char *)infile->value))
		{
			ft_print_error(infile->value, strerror(errno));
			return (EXIT_FAILURE);
		}
		if (infile->next)
		{
			ft_close_file(data->infile_fd, (char *)infile->value);
			if (*(int *)infile->key == DOUBLE_LESS)
				unlink((char *)infile->value);
		}
		else
		{
			if (*(int *)infile->key == DOUBLE_LESS)
			{
				data->infile_flag = 2;
				data->name_heredoc = (char *)infile->value;
			}
		}
		infile = infile->next;
	}
	return (EXIT_SUCCESS);
}

int	open_outfile(t_data *data, t_key_val *outfile)
{
	if (!outfile)
		return (EXIT_SUCCESS);
	data->outfile_flag = 1;
	if (open_outfile_bypass(data, outfile))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	open_outfile_bypass(t_data *data, t_key_val *outfile)
{
	while (outfile)
	{
		if (*(int *)outfile->key == GREATER)
		{
			if (open_outfile_greater(data, (char *)outfile->value))
			{
				ft_print_error(outfile->value, strerror(errno));
				return (EXIT_FAILURE);
			}
		}
		else if (*(int *)outfile->key == DOUBLE_GREATER)
		{
			if (open_outfile_doublegreater(data, (char *)outfile->value))
			{
				ft_print_error(outfile->value, strerror(errno));
				return (EXIT_FAILURE);
			}			
		}
		if (outfile->next)
			ft_close_file(data->outfile_fd, (char *)outfile->value);
		outfile = outfile->next;
	}
	return (EXIT_SUCCESS);
}

int	open_infile_outfile(t_data *data, t_exec *exec)
{
	if (open_infile(data, exec->infile))
	{
		data->exit_status = 1;
		return (EXIT_FAILURE);
	}
	if (open_outfile(data, exec->outfile))
	{
		data->exit_status = 1;
		if (data->infile_flag == 1)
			ft_close_file(data->infile_fd, NULL);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
