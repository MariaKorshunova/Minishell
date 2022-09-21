/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_joinvalue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:32:53 by refrain           #+#    #+#             */
/*   Updated: 2022/09/21 18:31:50 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	add_join_val_to_export(t_data *data, char *newkey,
									char *newvalue, char *oldvalue)
{
	char	*joinvalue;

	joinvalue = ft_strjoin(oldvalue, newvalue);
	if (!oldvalue)
		return (-1);
	add_val_to_export(data, newkey, joinvalue);
	free (joinvalue);
	return (0);
}

static char	*find_new_key_for_joinval(char **cmd, int i)
{
	int		j;
	char	*newkey;

	j = 0;
	while (cmd[i][j] != '+' && cmd[i][j] != '\0')
		j++;
	newkey = ft_substr(cmd[i], 0, j);
	if (!newkey)
		return (NULL);
	return (newkey);
}

int	ft_malloc_error(char *name)
{
	if (!name)
		return (-1);
	return (0);
}

int	ft_export_join(char **cmd, t_data *data, int i)
{
	int		j;
	char	*newkey;
	char	*newvalue;
	char	*oldvalue;

	j = 0;
	newkey = find_new_key_for_joinval(cmd, i);
	ft_malloc_error(newkey);
	newvalue = find_new_value(cmd, newkey, i);
	ft_malloc_error(newvalue);
	oldvalue = key_value_search_with_key(data->env, newkey);
	while (cmd[i][j] != '=' && cmd[i][j] != '\0')
		j++;
	if (cmd[i][j - 1] == '+')
	{
		if (!find_key(data->env, newkey))
			lst_addback_new_key_value(&data->env, newkey, newvalue);
		else if (newvalue && !oldvalue)
			add_val_to_export(data, newkey, newvalue);
		else if (newvalue && oldvalue)
			add_join_val_to_export(data, newkey, newvalue, oldvalue);
	}
	free (newkey);
	free (newvalue);
	return (EXIT_SUCCESS);
}
