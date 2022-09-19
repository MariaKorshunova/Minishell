/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 03:11:50 by refrain           #+#    #+#             */
/*   Updated: 2022/09/19 23:22:32 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_check_arg(char **cmd)
{
	int	i;
	int	j;
	int	exit_flag;

	i = 1;
	j = 0;
	while (cmd && cmd[i])
	{
		if (!(ft_isalpha((cmd[i][j])) && cmd[i][j] != '_') ||
			(ft_strchr(cmd[i], '?') || ft_strchr(cmd[i], ':')
			|| ft_strchr(cmd[i], '/') || ft_strchr(cmd[i], '.')))
		{
			ft_export_unset_print_error(cmd[0], cmd[i],
				"not a valid identifier");
			i++;
			exit_flag = 1;
		}
		else
			return (0);
	}
	if (exit_flag)
		return (1);
	return (0);
}

static	void	ft_swap(char **lhs, char **rhs)
{
	char	*tmp;

	tmp = *lhs;
	*lhs = *rhs;
	*rhs = tmp;
}

void	ft_bubble_sort(char **arr)
{
	int	i;
	int	j;
	int	size;

	size = 0;
	while (*(arr + size) != NULL)
		size++;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (ft_strcmp(arr[j], arr[j + 1]) > 0)
				ft_swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

int	ft_print_sorted_array(t_data *data, char *str)
{
	int		i;
	int		i_pos;
	char	*name;

	i = 0;
	i_pos = ft_strchr_pos(str, '=');
	name = ft_substr(str, 0, i_pos);
	if (!name)
		return (EXIT_FAILURE);
	printf("declare -x ");
	while (str[i] != '=')
		printf("%c", str[i++]);
	if (!key_value_search_with_key(data->env, name))
	{
		printf("\n");
		return (EXIT_SUCCESS);
	}
	printf("%c", str[i++]);
	printf("\"");
	while (str[i])
		printf("%c", str[i++]);
	printf("\"\n");
	return (EXIT_SUCCESS);
}

int	export_without_args(t_data *data)
{
	int		i;

	i = 0;
	ft_bubble_sort(data->env_arr);
	while (data->env_arr && (data->env_arr)[i])
		ft_print_sorted_array(data, (data->env_arr)[i++]);
	return (0);
}

char	*find_new_value(char **cmd, char *newkey)
{
	int		i;
	int		j;
	char	*newvalue;

	i = 1;
	while (cmd && cmd[i])
	{		
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
		i++;
	}
	return (newvalue);
}

char	*find_new_key(char **cmd)
{
	int		i;
	int		j;
	char	*newkey;

	i = 1;
	while (cmd && cmd[i])
	{		
		j = 0;
		while (cmd[i][j] != '=' && cmd[i][j] != '\0')
			j++;
		newkey = ft_substr(cmd[i], 0, j);
		if (!newkey)
			return (NULL);
		i++;
	}
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

int	export_add_new_key_value(char **cmd, t_data *data)
{
	char	*newkey;
	char	*newvalue;
	char	*oldkey;
	int		i;

	i = 1;
	newkey = find_new_key(cmd);
	newvalue = find_new_value(cmd, newkey);
	oldkey = find_key(data->env, newkey);
	printf("your newkey %s\n you new value %s\n your oldkey %s\n", newkey, newvalue, oldkey);
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

int	ft_export(char **cmd, t_data *data)
{
	int		i;
	int		ret;

	i = 0;
	if (!cmd[1])
		export_without_args(data);
	if (ft_check_arg(cmd))
		return (1);
	ret = export_add_new_key_value(cmd, data);
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
