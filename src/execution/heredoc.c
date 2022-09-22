/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:08:34 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/22 04:52:45 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	ft_heredoc(char *path_tmp, t_key_val *infile);
static char	*create_filename_heredoc(char *path_tmp);
static char	*join_path_index(char *path_tmp, int i);
static int	get_next_line_heredoc(char *stop, int fd);

int	open_heredoc(t_data *data, t_exec *exec)
{
	char		*path_tmp;
	t_key_val	*tmp;

	path_tmp = get_path_tmp(data);
	if (!path_tmp)
		return (EXIT_FAILURE);
	while (exec)
	{
		tmp = exec->infile;
		while (tmp)
		{
			if (*(int *)tmp->key == DOUBLE_LESS)
			{
				if (ft_heredoc(path_tmp, tmp))
				{
					free(path_tmp);
					return (EXIT_FAILURE);
				}
			}
			tmp = tmp->next;
		}
		exec = exec->next;
	}
	free(path_tmp);
	return (EXIT_SUCCESS);
}

static int	ft_heredoc(char *path_tmp, t_key_val *infile)
{
	char	*filename;
	int		fd;

	filename = create_filename_heredoc(path_tmp);
	if (!filename)
		return (EXIT_FAILURE);
	fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 0644);
	if (fd == -1)
	{
		free(filename);
		return (EXIT_FAILURE);
	}
	if (get_next_line_heredoc((char *)infile->value, fd))
	{
		ft_close_file(fd, (char *)infile->value);
		free(filename);
		return (EXIT_FAILURE);
	}
	free(infile->value);
	infile->value = filename;
	return (EXIT_SUCCESS);
}

static char	*create_filename_heredoc(char *path_tmp)
{
	int		i;
	char	*name;

	i = 0;
	while (1)
	{
		name = join_path_index(path_tmp, i);
		if (access(name, F_OK | W_OK) == -1)
			break ;
		free(name);
		i++;
	}
	return (name);
}

static char	*join_path_index(char *path_tmp, int i)
{
	char	*index;
	char	*name_index;
	char	*path_name;

	index = NULL;
	name_index = NULL;
	path_name = NULL;
	index = ft_itoa(i);
	if (!index)
		return (NULL);
	name_index = ft_strjoin("minishell_heredoc_", index);
	free(index);
	if (!name_index)
		return (NULL);
	path_name = ft_strjoin(path_tmp, name_index);
	free(name_index);
	return (path_name);
}

static int	get_next_line_heredoc(char *stop, int fd)
{
	char	*line;
	int		len_limiter;

	len_limiter = ft_strlen(stop);
	while (1)
	{
		ft_putstr_fd(HEREDOC_PROMPT, 1);
		//reading
		line = get_next_line(STDIN_FILENO);
		if (!line)
			return (EXIT_SUCCESS);
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
