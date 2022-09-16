/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 23:22:42 by refrain           #+#    #+#             */
/*   Updated: 2022/09/16 21:31:40 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_chdir(char *path, char **cmd)
{
	if (chdir(path))
	{
		ft_builtin_print_error(cmd[0], path, strerror(errno));
		return (1);
	}
	return (0);
}

static int	ft_cd_util(t_data *data, char *oldpwd, char *pwd)
{
	char	*new_pwd;

	if (!oldpwd)
	{
		if (lst_addback_new_key_value(&data->env, "OLDPWD", pwd))
			return (-1);
	}
	if (oldpwd)
	{
		if (ft_put_new_value(data->env, "OLDPWD", pwd) == -1)
			return (-1);
	}
	if (pwd)
	{
		new_pwd = getcwd(NULL, 0);
		if (ft_put_new_value(data->env, "PWD", new_pwd) == -1)
			return (-1);
		free (new_pwd);
	}
	return (0);
}

int	ft_cd(char **cmd, t_data *data)
{
	char	*home;
	char	*pwd;
	char	*oldpwd;
	int		ret_status;

	home = key_value_search_with_key(data->env, "HOME");
	pwd = key_value_search_with_key(data->env, "PWD");
	oldpwd = key_value_search_with_key(data->env, "OLDPWD");
	if (!home || !pwd)
	{
		ft_putstr_fd("Environment error\n", 2);
		return (-1);
	}
	ret_status = change_dir(cmd, home, pwd, oldpwd);
	if (ret_status == 1)
	{
		data->exit_status = 1;
		return (data->exit_status);
	}
	if (ret_status == -1)
		return (-1);
	else
		ret_status = ft_cd_util(data, oldpwd, pwd);
	data->exit_status = 0;
	return (data->exit_status);
}
