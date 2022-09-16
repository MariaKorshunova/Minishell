/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_change_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 03:40:05 by refrain           #+#    #+#             */
/*   Updated: 2022/09/16 03:41:20 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	change_dir_util(char **cmd, char *home)
{
	int	ret;

	ret = home_directory(cmd, home);
	if (ret == 1)
		return (1);
	if (ret == -1)
		return (-1);
	return (0);
}

int	change_dir(char **cmd, char *home, char *pwd, char *oldpwd)
{
	int		ret;
	char	*tmp;

	ret = 0;
	if (!cmd[1] || !ft_strncmp(cmd[1], "~", 1))
		ret = change_dir_util(cmd, home);
	else if (!ft_strcmp(cmd[1], "."))
		ret = ft_chdir(pwd, cmd);
	else if (!ft_strcmp(cmd[1], "-"))
		ret = ft_oldpwd(oldpwd);
	else if (!ft_strcmp(cmd[1], ".."))
	{
		tmp = ft_cut_string(pwd);
		if (tmp == NULL)
			return (-1);
		ft_chdir(tmp, cmd);
		free(tmp);
	}
	else
		ret = ft_chdir(cmd[1], cmd);
	return (ret);
}
