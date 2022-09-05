/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:40:46 by refrain           #+#    #+#             */
/*   Updated: 2022/09/05 19:58:20 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "builtins.h"

// void	update_env(t_data *data, char *key, char *value, int has_equal)
// {
// 	t_data  *new;

// 	new = find_env(head, key);
// 	if (env == NULL)
// 		add_env_back(&head, key, value, has_equal);
// 	else
// 	{
// 		if (env->value)
// 		{
// 			free(env->value);
// 			if (value)
// 				env->value = ft_strdup(value);
// 			else
// 				env->value = 0;
// 		}
// 		else
// 		{
// 			if (value)
// 				env->value = ft_strdup(value);
// 		}
// 		env->has_equal = has_equal;
// 	}
// }

// char	*find_env_val(t_data *data, char *key)
// {
// 	t_data  *new;

// 	new = data;
// 	while (new)
// 	{
// 		if (!ft_strcmp(new->env->key, key))
// 			return (new->env->value);
// 		new->env = new->env->next;
// 	}
// 	return ("");
// }

// int change_dir(t_data *data, char *path)
// {
//     char    *buf;
//     int     i;

//     if (!ft_strncmp(path, "~", 1))
// 		buf = ft_strdup(find_env_val(data->env, "HOME"));
// 	else if (!ft_strncmp(path, "-", 1))
// 		buf = ft_strdup(find_env_val(data->env, "OLDPWD"));
// 	else
// 		buf = ft_strdup(path);
// 	if (!buf)
// 		exit(1);
// 	i = chdir(buf);
// 	free(buf);
// 	return (i);
// }

// int ft_cd(t_data *data, char **cmd)
// {
//     char    pwd;

//     (void)cmd;
//     if (!cmd[1])
//         change_dir(data, "~");
//     else if (change_dir(data, cmd[1]) == -1)
// 	{
// 		printf("bash: cd: %s: No such file or directory\n", cmd[1]);
// 		data->exit_flag = 1;
// 	}
// 	else
// 	{
// 		getcwd(pwd, 0);
// 		update_env(data, "OLDPWD", find_env_val(data, "PWD"), 1);
// 		update_env(data, "PWD", pwd, 1);
// 		data->exit_flag = 0;
// 	}
// 	return (0);
// }

// char	**ft_example1(void)
// {
// 	char	**str;

// 	str = (char **)malloc (2 * sizeof(char *));
// 	str[0] = ft_strdup("pwd");
// 	// str[1] = ft_strdup(" ");
// 	str[1] = NULL;
// 	// str[3] = ft_strdup("-n");
// 	return (str);
// }

// char	**ft_example2(void)
// {
// 	char	**str;

// 	str = (char **)malloc (2 * sizeof(char *));
// 	str[0] = ft_strdup("pwd");
// 	// str[1] = ft_strdup(" ");
// 	str[1] = NULL;
// 	// str[3] = ft_strdup("-n");
// 	return (str);
// }

// char	**ft_example(void)
// {
// 	char	**str;

// 	str = (char **)malloc (2 * sizeof(char *));
// 	str[0] = ft_strdup("cd");
// 	// str[1] = ft_strdup(" ");
// 	str[1] = NULL;
// 	// str[3] = ft_strdup("-n");
// 	return (str);
// }