/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:08:34 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/08 17:46:19 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	ft_heredoc(t_data *data, t_key_val *infile)
{
	char	*line;
	int		eof;

	(void) data;
	eof = 1;
	while (eof)
	{
		line = readline(">");
		if (!line)
			return (EXIT_FAILURE);
		if (ft_strcmp(line, (char *)infile->value) == 0)
		{
			free(line);
			eof = 0;
		}
		else
		{
			ft_putstr_fd(line, STDIN_FILENO);
			free(line);
		}
	}
	return (EXIT_SUCCESS);
}
