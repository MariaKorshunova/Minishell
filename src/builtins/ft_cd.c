/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 23:22:42 by refrain           #+#    #+#             */
/*   Updated: 2022/09/14 03:26:16 by refrain          ###   ########.fr       */
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

char	*home_util(char **cmd, char *home)
{
	char	*tmp;

	if (!cmd || !home)
		return (0);
	tmp = ft_cut_string(home);
	cmd[1] = ft_strjoin(tmp, cmd[1] + 1);
	if (!cmd[1])
		return (NULL);
	free(tmp);
	return (cmd[1]);
}

int	home_directory(char **cmd, char *home)
{
	char	*tmp;

	if (!cmd || !home)
		return (0);
	if (!cmd[1] || !ft_strcmp(cmd[1], "~"))
		chdir(home);
	else
	{
		if (!ft_strncmp(cmd[1], "~/", 2))
		{
			tmp = cmd[1] + 1;
			cmd[1] = ft_strjoin(home, "/");
			if (!cmd[1])
				return (-1);
			cmd[1] = ft_strjoin(cmd[1], tmp);
			if (!cmd[1])
				return (-1);
		}
		else
			cmd[1] = home_util(cmd, home);
		chdir(cmd[1]);
		free(cmd[1]);
	}
	return (0);
}

int	ft_oldpwd(char *oldpwd)
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
		chdir(oldpwd);
		printf("%s\n", oldpwd);
	}
	return (0);
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
		ft_oldpwd(oldpwd);
	else if (!ft_strcmp(cmd[1], ".."))
	{
		tmp = ft_cut_string(pwd);
		chdir(tmp);
		free(tmp);
	}
	else
		ret = chdir(cmd[1]);
	return (ret);
}

char	*put_new_value(t_key_val *env, char	*key, char *newval)
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
				return (0);
			break ;
		}
		temp = temp->next;
	}
	return ((char *)temp->value);
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
		ft_print_error(cmd[1], "No such file or directory");
		data->exit_status = 1;
		return (data->exit_status);
	}
	// else
	// {
	// 	if (!oldpwd)
				
	// }
	oldpwd = put_new_value(data->env, "OLDPWD", pwd);
	pwd = put_new_value(data->env, "PWD", getcwd(NULL, 0));
	data->exit_status = 0;
	return (data->exit_status);
}
