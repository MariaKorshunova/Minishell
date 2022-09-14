/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:08:34 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/14 15:09:40 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

// static int	get_next_line_heredoc(char *stop, int fd);

int	ft_heredoc(t_data *data, t_key_val *token_list)
{
	char	*path_tmp;
	char	*filename;

	(void)token_list;
	path_tmp = get_path_tmp(data);
	if (!path_tmp)
		return (EXIT_FAILURE);
	printf("path_tmp=%s\n", path_tmp);
	// filename = create_filename_heredoc(path_tmp);
	printf("filename=%s\n", filename);
	free(path_tmp);
	return (EXIT_SUCCESS);
}

// static char	*create_filename_heredoc(char *path_tmp)
// {
// 	int	i;

// 	if (access())
// }

// static int	get_next_line_heredoc(char *stop, int fd)
// {
// 	char	*line;
// 	int		len_limiter;

// 	len_limiter = ft_strlen(stop);
// 	while (1)
// 	{
// 		ft_putstr_fd(HEREDOC_PROMPT, 1);
// 		line = get_next_line(STDIN_FILENO);
// 		if (!line)
// 		{
// 			perror(PREFIX_ERROR);
// 			return (EXIT_FAILURE);
// 		}
// 		if (ft_strncmp(line, stop, len_limiter) == 0)
// 		{
// 			if (line[len_limiter] == '\n')
// 			{
// 				free(line);
// 				break ;
// 			}
// 		}
// 		ft_putstr_fd(line, fd);
// 		free(line);
// 	}
// 	return (EXIT_SUCCESS);
// }
