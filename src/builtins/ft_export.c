/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 03:11:50 by refrain           #+#    #+#             */
/*   Updated: 2022/09/19 22:23:40 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_check_arg(char **cmd)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (cmd[i][j] != '_' || !ft_isalpha(cmd[i][j]) || ft_strchr(cmd[i], '?'))
	{
		ft_export_unset_print_error(cmd[0], cmd[i], "not a valid identifier");
		i++;
		return (1);
	}
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

void	ft_print_sorted_array(char *str)
{
	int	i;
	int	i_pos;

	i = 0;
	i_pos = ft_strchr_pos(str, '=');
	printf("declare -x ");
	if (i_pos == -1)
		printf("%c\n", str[i++]);
	else
	{
		while (str[i] != '=')
			printf("%c", str[i++]);
		printf("%c", str[i++]);
		printf("\"");
		while (str[i])
			printf("%c", str[i++]);
		printf("\"\n");
	}
}

int	ft_export(char **cmd, t_data *data)
{
	int		i;
	int		j;
	char	*newkey;
	char	*oldvalue;
	char	*newvalue;
	t_key_val	*lstnew;
	// t_key_val	*tmp;

	i = 0;
	// if (ft_check_arg(cmd))
	// 	return (1);
	if (!cmd[1])
	{
		ft_bubble_sort(data->env_arr);
		while (data->env_arr && (data->env_arr)[i])
			ft_print_sorted_array((data->env_arr)[i++]);
		return (0);
	}
	i = 1;
	while (cmd && cmd[i])
	{
		j = 0;
		while (cmd[i][j] != '=' && cmd[i][j] != '\0')
			j++;
		newkey = ft_substr(cmd[i], 0, j);
		if (!newkey)
			return (-1);
		if (cmd[i][j] == '\0')
			newvalue = NULL;
		else
		{
			newvalue = ft_substr(cmd[i], j + 1, ft_strlen(cmd[i]) - j - 1);
			if (!newvalue)
			{
				free (newkey);
				return (-1);
			}	
		}
		// printf("newkey=%s newvalue=%s", newkey, newvalue);
		// tmp = data->env;
		// oldvalue = key_value_search_with_key(tmp, newkey);
		oldvalue = NULL;
		if (!oldvalue)
		{
			lstnew = lstnew_key_value(newkey, newvalue);
			if (!lstnew)
			{
				free (newkey);
				free (newvalue);
				return (-1);
			}
			lstadd_back_key_value(&data->env, lstnew);
		}
		// else
		// {
		// 	if (ft_put_new_value(data->env, newkey, newvalue) == -1)
		// 	{
		// 		free (newkey);
		// 		free (newvalue);
		// 		return (-1);
		// 	}
		// }
		i++;
	}
	data->exit_status = 0;
	return (data->exit_status);
}
