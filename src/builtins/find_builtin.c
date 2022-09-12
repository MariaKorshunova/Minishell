/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 23:01:13 by refrain           #+#    #+#             */
/*   Updated: 2022/09/12 15:39:06 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	find_builtin(char **cmd, t_data *data)
{
	if (ft_strcmp((cmd)[0], "echo") == 0 || ft_strcmp((cmd)[0], "ECHO") == 0)
	{
		ft_echo(cmd);
		return (1);
	}
	else if (ft_strcmp((cmd)[0], "pwd") == 0 || ft_strcmp((cmd)[0], "PWD") == 0)
	{
		ft_pwd();
		return (1);
	}
	else if (ft_strcmp((cmd)[0], "cd") == 0)
	{
		ft_cd(cmd, data);
		return (1);
	}
	else if (ft_strcmp((cmd)[0], "env") == 0 || ft_strcmp((cmd)[0], "ENV") == 0)
	{
		ft_env(data);
		return (1);
	}
	else if (ft_strcmp((cmd)[0], "exit") == 0)
	{
		ft_exit(cmd, data);
		return (1);
	}
	return (0);
}
