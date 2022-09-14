/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:08:34 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/10 16:56:33 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	get_next_line_heredoc(char *stop, int fd);

int	ft_heredoc(t_data *data, t_key_val *infile)
{
	int		pipe_heredoc[2];

	if (pipe(pipe_heredoc) == -1)
	{
		perror(PREFIX_ERROR);
		return (EXIT_FAILURE);
	}
	data->infile_fd = pipe_heredoc[0];
	if (get_next_line_heredoc((char *)infile->value, pipe_heredoc[1]))
	{
		perror (PREFIX_ERROR);
		ft_close_file(pipe_heredoc[0], NULL);
		ft_close_file(pipe_heredoc[1], NULL);
		return (EXIT_FAILURE);
	}
	ft_close_file(pipe_heredoc[1], NULL);
	return (EXIT_SUCCESS);
}

static int	get_next_line_heredoc(char *stop, int fd)
{
	char	*line;
	int		len_limiter;

	len_limiter = ft_strlen(stop);
	while (1)
	{
		ft_putstr_fd(HEREDOC_PROMPT, 1);
		line = get_next_line(STDIN_FILENO);
		if (!line)
		{
			perror(PREFIX_ERROR);
			return (EXIT_FAILURE);
		}
		if (ft_strncmp(line, stop, len_limiter) == 0)
		{
			if (line[len_limiter] == '\n')
			{
				free(line);
				break ;
			}
		}
		ft_putstr_fd(line, fd);
		free(line);
	}
	return (EXIT_SUCCESS);
}
