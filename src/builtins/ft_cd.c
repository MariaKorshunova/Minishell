/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 23:22:42 by refrain           #+#    #+#             */
/*   Updated: 2022/09/16 03:47:29 by refrain          ###   ########.fr       */
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

static int	ft_oldpwd(char *oldpwd)
{
	t_data	data;

	if (oldpwd == NULL)
	{
		ft_print_error("cd", "OLDPWD not set");
		data.exit_status = 1;
		return (data.exit_status);
	}
	else
	{
		if (chdir(oldpwd))
			return (1);
		printf("%s\n", oldpwd);
	}
	return (0);
}

static int	ft_cd_util(char **cmd, t_data *data, char *oldpwd, char *pwd)
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
		ret_status = ft_cd_util(cmd, data, oldpwd, pwd);
	data->exit_status = 0;
	return (data->exit_status);
}
