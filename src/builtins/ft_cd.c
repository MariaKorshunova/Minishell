/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 23:22:42 by refrain           #+#    #+#             */
/*   Updated: 2022/09/14 18:22:03 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

// t_list	ft_add_oldpwd(char **cmd, t_data *data)
// {
// 	t_key_val	*temp;

// 	temp = data->env;
// 	while (temp->next)
// 		temp = temp->next;
// 	(char *)temp->key = strdup()
		
// }

// char	*home_util(char **cmd, char *home)
// {
// 	char	*tmp;

// 	if (!cmd || !home)
// 		return (0);
// 	tmp = ft_cut_string(home);
// 	cmd[1] = ft_strjoin(tmp, cmd[1] + 1);
// 	if (!cmd[1])
// 		return (NULL);
// 	free(tmp);
// 	return (cmd[1]);
// }

static int	ft_chdir(char *path, char **cmd)
{
	if (chdir(path))
	{
		ft_builtin_print_error(cmd[0], path, strerror(errno));
		return (1);
	}
	return (0);
}

static int	home_directory(char **cmd, char *home)
{
	char	*full_cmd;
	char	*tmp;

	if (!cmd || !home)
		return (0);
	full_cmd = NULL;
	if (!cmd[1] || !ft_strcmp(cmd[1], "~"))
	{
		if (ft_chdir(home, cmd))
			return (1);
		return (0);
	}
	if (!ft_strncmp(cmd[1], "~/", 2))
	{
		tmp = cmd[1] + 1;
		full_cmd = ft_strjoin(home, tmp);
		if (!full_cmd)
			return (-1);
	}
	if (ft_chdir(full_cmd, cmd))
		return (1);
	free(full_cmd);
	return (0);
}

int	ft_oldpwd(char *oldpwd, char **cmd)
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
		ft_chdir(oldpwd, cmd);
		printf("%s\n", oldpwd);
	}
	return (0);
}

int	change_dir(char **cmd, char *home, char *pwd, char *oldpwd)
{
	char	*tmp;
	int		ret;

	if (!cmd[1] || !ft_strncmp(cmd[1], "~", 1))
	{
		ret = home_directory(cmd, home);
		if (ret == 1)
			return (1);
		if (ret == -1)
			return (-1);
	}
	//start from here
	else if (!ft_strcmp(cmd[1], "."))
		ft_chdir(pwd, cmd);
	else if (!ft_strcmp(cmd[1], "-"))
		ft_oldpwd(oldpwd, cmd);
	else if (!ft_strcmp(cmd[1], ".."))
	{
		tmp = ft_cut_string(pwd);
		if (tmp == NULL)
			return (-1);
		ft_chdir(tmp, cmd);
		free(tmp);
	}
	else
		ft_chdir(cmd[1], cmd);
	return (0);
}

int	put_new_value(t_key_val *env, char	*key, char *newval)
{
	t_key_val	*temp;

	temp = env;
	while (temp)
	{
		if (!ft_strcmp(key, (char *)temp->key))
		{
			free((char *)temp->value);
			temp->value = strdup(newval);
			if (!(temp->value))
				return (-1);
			break ;
		}
		temp = temp->next;
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
	if (!home || !pwd)
	{
		ft_putstr_fd("Environment error\n", 2);
		return (-1);
	}
	if (change_dir(cmd, home, pwd, oldpwd) == 1)
	{
		data->exit_status = 1;
		return (data->exit_status);
	}
	if (change_dir(cmd, home, pwd, oldpwd) == -1)
		return (-1);
	// else
	// {
	// 	if (!oldpwd)
				
	// }
	// if (oldpwd)
	// 	if (put_new_value(data->env, "OLDPWD", pwd))
	// 		return (-1);
	// if (put_new_value(data->env, "PWD", getcwd(NULL, 0)))
		// return (-1);
	data->exit_status = 0;
	return (data->exit_status);
}
