/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 23:22:42 by refrain           #+#    #+#             */
/*   Updated: 2022/09/07 04:18:15 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	home_directory(char **cmd, char *home)
{
	char	*tmp;

	if (!cmd[1] || !ft_strcmp(cmd[1], "~"))
		chdir(home);
	else
	{
		if (!ft_strncmp(cmd[1], "~/", 2))
		{
			tmp = cmd[1] + 1;
			cmd[1] = ft_strjoin(home, "/");
			cmd[1] = ft_strjoin(cmd[1], tmp);
		}
		else
		{
			tmp = ft_cut_string(home);
			cmd[1] = ft_strjoin(tmp, cmd[1] + 1);
			free(tmp);
		}
		chdir(cmd[1]);
	}
	return (0);
}

void	ft_oldpwd(char *oldpwd)
{
	if (oldpwd == NULL)
	{
		ft_error("cd", "OLDPWD not set\n");
		exit (1);
	}
	else
	{
		chdir(oldpwd);
		printf("%s\n", oldpwd);
	}
}

int	change_dir(char **cmd, char *home, char *pwd, char *oldpwd)
{
	char	*tmp;
	int		ret;

	ret = 0;
	if (!cmd[1] || !ft_strncmp(cmd[1], "~", 1))
		home_directory(cmd, home);
	else if (!ft_strcmp(cmd[1], "."))
		chdir(pwd);
	else if (!ft_strcmp(cmd[1], "-"))
	{
		ft_oldpwd(oldpwd);
	}
	else if (!ft_strcmp(cmd[1], ".."))
	{
		tmp = ft_cut_string(pwd);
		ret = chdir(tmp);
		free(tmp);
	}
	else
		ret = chdir(cmd[1]);
	return (ret);
}

int	put_new_value(t_key_val *env, char	*key, char *newval)
{
	while (env)
	{
		if (!ft_strcmp(key, (char *)env->key))
		{
			env->value = newval;
			break ;
		}
		env = env->next;
	}
	return (0);
}

int	ft_cd(char **cmd, t_data *data)
{
	char	*home;
	char	*pwd;
	char	*oldpwd;

	home = key_value_search_with_key(data->env, "HOME");
	pwd = key_value_search_with_key(data->env, "PWD");
	oldpwd = key_value_search_with_key(data->env, "OLDPWD");
	if (change_dir(cmd, home, pwd, oldpwd))
	{
		ft_error(cmd[1], "No such file or directory");
		exit (1);
	}
	if (put_new_value(data->env, "OLDPWD", pwd))
		return (1);
	if (put_new_value(data->env, "PWD", getcwd(NULL, 0)))
		return (1);
	exit (0);
}
