/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_home_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 02:57:35 by refrain           #+#    #+#             */
/*   Updated: 2022/09/16 03:10:56 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	home_util(char **cmd, char *home)
{
	char	*tmp;
	char	*full_cmd;

	full_cmd = NULL;
	if (!ft_strncmp(cmd[1], "~/", 2))
	{
		tmp = cmd[1] + 1;
		full_cmd = ft_strjoin(home, tmp);
		if (!full_cmd)
			return (-1);
	}
	if (ft_chdir(full_cmd, cmd))
	{
		free(full_cmd);
		return (1);
	}
	free(full_cmd);
	return (0);
}

int	home_directory(char **cmd, char *home)
{
	if (!cmd || !home)
		return (0);
	if (!cmd[1] || !ft_strcmp(cmd[1], "~"))
	{
		if (ft_chdir(home, cmd))
			return (1);
		return (0);
	}
	home_util(cmd, home);
	return (0);
}
