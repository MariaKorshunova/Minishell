/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 23:22:42 by refrain           #+#    #+#             */
/*   Updated: 2022/08/29 19:06:15 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	put_envp_value(t_data *data, char *key, char *new)
{
	int	i;
	int	j;

	if (!data || !key)
		return (1);
	i = pos_in_envp(data, key);
	if (i == -1)
		return (1);
	j = 0;
	while (j < i)
	{
		data->env = data->env->next;
		i++;
	}
	data->env->value = new;
	return (0);
}

char	*get_str(char *str)
{
	int		i;
	char	*new;

	// if (!str)
	// 	return (NULL);
	i = ft_strlen(str);
	while (str[i])
		i--;
	new = ft_substr(str, 0, i + 1);
	return (new);
}

int	ft_home(char **cmd, char *home)
{
	char	*tmp;

	if (cmd[1] == NULL || !ft_strcmp(cmd[1], "~"))
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
			tmp = get_str(home);
			cmd[1] = ft_strjoin(tmp, cmd[1] + 1);
			free (tmp);
		}
		chdir (cmd[1]);
	}
	return (0);
}

int	change_directory(char **cmd, char *home, char *pwd, char *oldpwd)
{
	char	*tmp;
	
	if (cmd[1] == NULL || !ft_strncmp(cmd[1], "~", 1))
		ft_home(cmd, home);
	else if (!ft_strcmp(cmd[1], "."))
		chdir(pwd);
	else if (!ft_strcmp(cmd[1], "-"))
	{
		chdir(oldpwd);
		printf("%s\n", oldpwd);
	}
	else if (!ft_strcmp(cmd[1], ".."))
	{
		tmp = get_str(pwd);
		chdir(tmp);
		free (tmp);
	}
	else
		chdir(cmd[1]);
	return (0);
}

// int	ft_cd(char **cmd)
// {
// 	if (*(cmd + 1) == NULL || ft_strcmp(cmd[1], "~"))
// 	{
// 		*(cmd + 1) = ft_home();
// 		if (*(cmd + 1) == NULL)
// 		{
// 			printf("HOME not set\n");
// 			return (0);
// 		}
// 		if (cmd[1][0] == '\0')
// 			return (0);
// 	}
// }

// int	pos_in_envp(t_data *data, char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (!data || !str)
// 		return (-1);
// 	while (data->env)
// 	{
// 		if (!ft_strcmp(data->env->key, str))
// 			return (i);
// 		i++;
// 		data->env = data->env->next;
// 	}
// 	return (-1);
// }

char	*get_value_from_envp(t_data *data, char *str)
{
	int		i;
	int		j;
	char	*val;

	if (!data || !str)
		return (NULL);
	i = pos_in_envp(data, str);
	if (i == -1)
		return (NULL);
	j = 0;
	while (j < i)
	{
		data->env = data->env->next;
		j++;
	}
	val = ft_strdup(data->env->value);
	return (val);
}

int	ft_cd(char **cmd, t_data *data)
{
	char	*home;
	char	*pwd;
	char	*oldpwd;
	
	if (!cmd || !data)
		return (1);
	home = get_value_from_envp(data, "HOME");
	printf("%s", get_value_from_envp(data, "HOME"));
	pwd = get_value_from_envp(data, "PWD");
	oldpwd = get_value_from_envp(data, "OLDPWD");
	if (!home || !pwd || !oldpwd)
		return (1);
	change_directory(cmd, home, pwd, oldpwd);
	if (put_envp_value(data, "OLDPWD", pwd))
		return (1);
	if (put_envp_value(data, "PWD", getcwd(NULL, 0)))
		return (1);
	free (home);
	free(oldpwd);
	return (0);
}

// char	**ft_example(void)
// {
// 	char	**str;

// 	str = (char **)malloc (2 * sizeof(char *));
// 	str[0] = ft_strdup("cd");
// 	// str[1] = ft_strdup("-n");
// 	// str[2] = ft_strdup("-n");
// 	// str[3] = ft_strdup("-n");
// 	return (str);
// }

// int	main(void)
// {
// 	t_data *data;
// 	// data->env
// 	// envp_list = lexer("cd src");
// 	char **str = ft_example();
// 	find_builtin(str, data);
// 	free_2dimensional_array((void **)str);
// 	// printf("%s\n", "hello");
// 	// printf("%s\n", str[0]);
// 	return (0);
// }
