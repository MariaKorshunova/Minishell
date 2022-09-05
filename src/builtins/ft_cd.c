/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 23:22:42 by refrain           #+#    #+#             */
/*   Updated: 2022/09/05 23:00:07 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

// int	put_value(t_data *data, char *key, char *new_val)
// {
// 	int	pos;
// 	int	i;

// 	pos = pos_in_envp(data, key);
// 	if (pos == -1)
// 		return (1);
// 	i = 0;
// 	while (i < pos)
// 	{
// 		data->env = data->env->next;
// 		i++;
// 	}
// 	data->env->value = new_val;
// 	return (0);
// }

char	*ft_cut_string(char *str)
{
	int		i;
	char	*new_str;

	if (!str)
		return (NULL);
	i = ft_strlen(str);
	while (str[i] != '/')
		i--;
	new_str = ft_substr(str, 0, i + 1);
	return (new_str);
}

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
		ret = chdir(oldpwd);
		printf("%s\n", oldpwd);
		if (!ft_strcmp(oldpwd, "(null)"))
			printf("bash: cd: OLDPWD not set");
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

// char	*get_value(t_data *data, char *str)
// {
// 	int		pos;
// 	char	*res;

// 	pos = pos_in_envp(data, str);
// 	if (pos == -1)
// 		return (NULL);
// 	res = ft_strdup(data->env->value);
// 	return (res);
// }

int	ft_cd(char **cmd, t_data *data)
{
	char	*home;
	char	*pwd;
	char	*oldpwd;
	
	home =  key_value_search_with_key(data->env, "HOME");
	pwd =  key_value_search_with_key(data->env, "PWD");
	oldpwd =  key_value_search_with_key(data->env, "OLDPWD");
	printf("%s", oldpwd);
	// if (!ft_strcmp(oldpwd, "(null)"))
	// 	return (NULL);
	// printf("your home is: %s\n", home);
	// printf("your pwd is: %s\n", pwd);
	// printf("your oldpwd is: %s\n", oldpwd);
	if (!home || !pwd || !oldpwd)
		return (1);
	if (change_dir(cmd, home, pwd, oldpwd))
	{
		ft_error(cmd[1], "No such file or directory\n");
		// printf("bash: cd: No such file or directory\n");
		printf("hello");
	}
	// if (put_value(data, "OLDPWD", pwd))
	// 	return (1);
	// if (put_value(data, "PWD", getcwd(NULL, 0)))
	// 	return (1);
	// printf("%s\n", pwd);
	free(home);
	free(oldpwd);
	return (0);
}

char	**ft_example1(void)
{
	char	**str;

	str = (char **)malloc (2 * sizeof(char *));
	str[0] = ft_strdup("pwd");
	// str[1] = ft_strdup(" ");
	str[1] = NULL;
	// str[3] = ft_strdup("-n");
	return (str);
}

char	**ft_example2(void)
{
	char	**str;

	str = (char **)malloc (2 * sizeof(char *));
	str[0] = ft_strdup("pwd");
	// str[1] = ft_strdup(" ");
	str[1] = NULL;
	// str[3] = ft_strdup("-n");
	return (str);
}

char	**ft_example(void)
{
	char	**str;

	str = (char **)malloc (3 * sizeof(char *));
	str[0] = ft_strdup("cd");
	str[1] = ft_strdup("-");
	str[2] = NULL;
	// str[3] = ft_strdup("-n");
	return (str);
}

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
