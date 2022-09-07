/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:49:46 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/07 18:35:55 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	ft_exec_without_path(t_data *data, t_exec **pipeline);
static void	ft_exec_with_path(t_data *data, t_exec **pipeline);
static void	error_execve(t_data *data, t_exec **pipeline);

void	ft_exec(t_data *data, t_exec **pipeline)
{
	ft_exec_without_path(data, pipeline);
	ft_exec_with_path(data, pipeline);
	ft_print_error((*pipeline)->cmd[0], "command not found");
	destructor_minishell(data);
	lstclear_exec(pipeline);
	exit(ERR_EXECUTE_CMD);
}

static void	ft_exec_without_path(t_data *data, t_exec **pipeline)
{
	if (access((*pipeline)->cmd[0], 01) == 0)
	{
		execve((*pipeline)->cmd[0], (*pipeline)->cmd, data->env_arr);
		error_execve(data, pipeline);
	}
	if (!data->bin_path)
	{
		ft_print_error((*pipeline)->cmd[0], "command not found");
		destructor_minishell(data);
		lstclear_exec(pipeline);
		exit(ERR_EXECUTE_CMD);
	}
}

static void	ft_exec_with_path(t_data *data, t_exec **pipeline)
{
	int		i;
	char	*cmd_with_path;

	i = 0;
	while (data->bin_path[i] != NULL)
	{
		cmd_with_path = ft_strjoin_with_endchar(data->bin_path[i],
				(*pipeline)->cmd[0], '/');
		if (!cmd_with_path)
			error_execve(data, pipeline);
		if (access(cmd_with_path, 01) == 0)
		{
			execve(cmd_with_path, (*pipeline)->cmd, data->env_arr);
			free(cmd_with_path);
			error_execve(data, pipeline);
		}
		free(cmd_with_path);
		i++;
	}
}

static void	error_execve(t_data *data, t_exec **pipeline)
{
	destructor_minishell(data);
	lstclear_exec(pipeline);
	perror(PREFIX_ERROR);
	exit (EXIT_FAILURE);
}
