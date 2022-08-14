/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 23:01:13 by refrain           #+#    #+#             */
/*   Updated: 2022/08/15 00:42:17 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	find_builtin(char **cmd, t_key_val *envp_list)
{
	if (ft_strcmp((cmd)[0], "echo") == 0)
		ft_echo(cmd);
	else if (ft_strcmp((cmd)[0], "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp((cmd)[0], "cd") == 0)
		ft_cd(cmd, envp_list);
}
