/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 23:01:13 by refrain           #+#    #+#             */
/*   Updated: 2022/08/18 23:51:36 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	find_builtin(char **cmd, t_data *data)
{
	if (ft_strcmp((cmd)[0], "echo") == 0 || ft_strcmp((cmd)[0], "ECHO") == 0)
		ft_echo(cmd);
	else if (ft_strcmp((cmd)[0], "pwd") == 0 || ft_strcmp((cmd)[0], "PWD") == 0)
		ft_pwd();
	// else if (ft_strcmp((cmd)[0], "cd") == 0)
	// 	ft_cd(cmd, envp_list);
	else if (ft_strcmp((cmd)[0], "env") == 0 || ft_strcmp((cmd)[0], "ENV") == 0)
		ft_env(data);
}
