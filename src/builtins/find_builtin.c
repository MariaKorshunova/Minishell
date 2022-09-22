/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 23:01:13 by refrain           #+#    #+#             */
/*   Updated: 2022/09/21 20:07:23 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	ft_add_function(char **cmd, t_data *data)
{
	if (ft_strcmp(cmd[0], "exit") == 0)
	{
		ft_exit(cmd, data);
		return (1);
	}
	else if (ft_strcmp(cmd[0], "env") == 0 || ft_strcmp(cmd[0], "ENV") == 0)
	{
		ft_env(data);
		return (1);
	}
	else if (ft_strcmp(cmd[0], "export") == 0)
	{
		if (ft_export(cmd, data) == -1)
			return (-1);
		return (1);
	}
	else if (ft_strcmp(cmd[0], "unset") == 0)
	{
		ft_unset(cmd, data);
		return (1);
	}
	return (0);
}

int	find_builtin(char **cmd, t_data *data)
{
	int	status;

	if (ft_strcmp(cmd[0], "echo") == 0 || ft_strcmp(cmd[0], "ECHO") == 0)
	{
		ft_echo(cmd);
		return (1);
	}
	else if (ft_strcmp(cmd[0], "pwd") == 0 || ft_strcmp(cmd[0], "PWD") == 0)
	{
		ft_pwd();
		return (1);
	}
	else if (ft_strcmp(cmd[0], "cd") == 0)
	{
		if (ft_cd(cmd, data) == -1)
			return (-1);
		return (1);
	}
	else
	{
		status = ft_add_function(cmd, data);
		return (status);
	}
	return (0);
}
