/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:49:46 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/10 17:06:08 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	ft_exec_without_path(t_data *data, t_exec **pipeline, t_exec *exec);
static void	ft_exec_with_path(t_data *data, t_exec **pipeline, t_exec *exec);
static void	error_execve(t_data *data, t_exec **pipeline);

void	ft_exec(t_data *data, t_exec **pipeline, t_exec *exec)
{
	if (exec->cmd[0] == NULL)
		exit (EXIT_SUCCESS);
	ft_exec_without_path(data, pipeline, exec);
	ft_exec_with_path(data, pipeline, exec);
	ft_print_error(exec->cmd[0], "command not found");
	destructor_minishell(data);
	lstclear_exec(pipeline);
	exit(ERR_EXECUTE_CMD);
}

static void	ft_exec_without_path(t_data *data, t_exec **pipeline, t_exec *exec)
{
	if (access(exec->cmd[0], 01) == 0)
	{
		execve(exec->cmd[0], exec->cmd, data->env_arr);
		error_execve(data, pipeline);
	}
	if (!data->bin_path)
	{
		ft_print_error(exec->cmd[0], "command not found");
		destructor_minishell(data);
		lstclear_exec(pipeline);
		exit(ERR_EXECUTE_CMD);
	}
}

static void	ft_exec_with_path(t_data *data, t_exec **pipeline, t_exec *exec)
{
	int		i;
	char	*cmd_with_path;

	i = 0;
	while (data->bin_path[i] != NULL)
	{
		cmd_with_path = ft_strjoin_with_endchar(data->bin_path[i],
				exec->cmd[0], '/');
		if (!cmd_with_path)
			error_execve(data, pipeline);
		if (access(cmd_with_path, 01) == 0)
		{
			execve(cmd_with_path, exec->cmd, data->env_arr);
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
