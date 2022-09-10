/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:08:34 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/10 13:39:15 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	ft_heredoc(t_data *data, t_key_val *infile)
{
	char	*line;
	int		len_limiter;
	int		pipe_heredoc[2];

	(void)data;
	if (pipe(pipe_heredoc) == -1)
	{
		perror(PREFIX_ERROR);
		return (EXIT_FAILURE);
	}
	// if (dup2)
	len_limiter = ft_strlen((char *)infile->value);
	while (1)
	{
		ft_putstr_fd(HEREDOC_PROMPT, 1);
		line = get_next_line(STDIN_FILENO);
		if (!line)
		{
			perror(PREFIX_ERROR);
			return (EXIT_FAILURE);
		}
		if (ft_strncmp(line, (char *)infile->value, len_limiter) == 0)
		{
			if (line[len_limiter] == '\n')
			{
				free(line);
				break ;
			}
		}
		ft_putstr_fd(line, 1);
		free(line);
	}
	return (EXIT_SUCCESS);
}
