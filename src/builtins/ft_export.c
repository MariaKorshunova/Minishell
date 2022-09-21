/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 03:11:50 by refrain           #+#    #+#             */
/*   Updated: 2022/09/21 04:08:25 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char	*find_new_value(char **cmd, char *newkey, int i)
{
	int		j;
	char	*newvalue;

	j = 0;
	while (cmd[i][j] != '=' && cmd[i][j] != '\0')
		j++;
	if (cmd[i][j] == '\0')
		newvalue = NULL;
	else
	{
		newvalue = ft_substr(cmd[i], j + 1, ft_strlen(cmd[i]) - j - 1);
		if (!newvalue)
		{
			free (newkey);
			return (NULL);
		}	
	}
	return (newvalue);
}

char	*find_new_key(char **cmd, int i)
{
	int		j;
	char	*newkey;

	j = 0;
	while (cmd[i][j] != '=' && cmd[i][j] != '\0')
		j++;
	newkey = ft_substr(cmd[i], 0, j);
	if (!newkey)
		return (NULL);
	return (newkey);
}

char	*find_key(t_key_val *env, char	*key)
{
	while (env)
	{
		if (!ft_strcmp(key, (char *)env->key))
		{
			return ((char *)env->key);
			break ;
		}
		env = env->next;
	}
	return (NULL);
}

int	export_add_new_key_value(char **cmd, t_data *data, int i)
{
	char	*newkey;
	char	*newvalue;
	char	*oldkey;

	newkey = find_new_key(cmd, i);
	newvalue = find_new_value(cmd, newkey, i);
	oldkey = find_key(data->env, newkey);
	if (!oldkey)
		lst_addback_new_key_value(&data->env, newkey, newvalue);
	else if (newvalue)
	{
		if (ft_put_new_value(data->env, newkey, newvalue) == -1)
		{
			free (newkey);
			free (newvalue);
			return (-1);
		}
	}
	return (0);
}

int	ft_export_join(char **cmd, t_data *data)
{
	int		i;
	int		j;
	char	*newkey;
	char	*newvalue;
	char	*oldkey;
	char	*join_value;

	i = 1;
	j = 0;
	newkey = find_new_key(cmd, i);
	newvalue = find_new_value(cmd, newkey, i);
	oldkey = find_key(data->env, newkey);
	while (cmd[i][j] != '+' && cmd[i][j] != '\0')
	{
		j++;
		if (cmd[i][j + 1] == '=')
		{
			if (!oldkey)
				lst_addback_new_key_value(&data->env, newkey, newvalue);
		}
		else if (newvalue)
		{
			join_value = ft_strjoin(data->env->value, newvalue);
			if (!join_value)
				return (EXIT_FAILURE);
			if (ft_put_new_value(data->env, newkey, join_value) == -1)
			{
				free (newkey);
				free (newvalue);
				return (-1);
			}
			free (join_value);
		}
	}
	return (EXIT_SUCCESS);
}

int	ft_export(char **cmd, t_data *data)
{
	int		i;
	int		ret;

	i = 1;
	if (!cmd[1])
		export_without_args(data);
	if (ft_check_arg(cmd))
	{
		data->exit_status = 1;
		return (data->exit_status);
	}
	while (cmd && cmd[i])
	{
		ret = export_add_new_key_value(cmd, data, i);
		i++;
	}
	// ft_export_join(cmd, data);
	data->exit_status = ret;
	return (data->exit_status);
}

// int	ft_export(char **cmd, t_data *data)
// {
// 	int		i;
// 	int		j;
// 	char	*newkey;
// 	char	*oldvalue;
// 	char	*newvalue;
// 	t_key_val	*lstnew;

// 	i = 0;
// 	if (!cmd[1])
// 		export_without_args(data);
// 	if (ft_check_arg(cmd))
// 		return (1);
// 	i = 1;
// 	while (cmd && cmd[i])
// 	{		
// 		j = 0;
// 		while (cmd[i][j] != '=' && cmd[i][j] != '\0')
// 			j++;
// 		newkey = ft_substr(cmd[i], 0, j);
// 		if (!newkey)
// 			return (-1);
// 		if (cmd[i][j] == '\0')
// 			newvalue = NULL;
// 		else
// 		{
// 			newvalue = ft_substr(cmd[i], j + 1, ft_strlen(cmd[i]) - j - 1);
// 			if (!newvalue)
// 			{
// 				free (newkey);
// 				return (-1);
// 			}	
// 		}
// 		oldvalue = NULL;
// 		if (!oldvalue)
// 		{
// 			lstnew = lstnew_key_value(newkey, newvalue);
// 			if (!lstnew)
// 			{
// 				free (newkey);
// 				free (newvalue);
// 				return (-1);
// 			}
// 			lstadd_back_key_value(&data->env, lstnew);
// 		}
// 		else
// 		{
// 			if (ft_put_new_value(data->env, newkey, newvalue) == -1)
// 			{
// 				free (newkey);
// 				free (newvalue);
// 				return (-1);
// 			}
// 		}
// 		i++;
// 	}
// 	data->exit_status = 0;
// 	return (data->exit_status);
// }