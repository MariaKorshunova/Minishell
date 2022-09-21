/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 03:11:50 by refrain           #+#    #+#             */
/*   Updated: 2022/09/21 18:05:15 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	add_val_to_export(t_data *data, char *newkey, char *newvalue)
{
	if (ft_put_new_value(data->env, newkey, newvalue) == -1)
	{
		free (newkey);
		free (newvalue);
		return (-1);
	}
	return (0);
}

static int	export_add_new_key_value(char **cmd, t_data *data, int i)
{
	char	*newkey;
	char	*newvalue;
	char	*oldkey;
	int		j;

	j = 0;
	newkey = find_new_key(cmd, i);
	newvalue = find_new_value(cmd, newkey, i);
	oldkey = find_key(data->env, newkey);
	while (cmd[i][j] != '=' && cmd[i][j] != '\0')
		j++;
	if (cmd[i][j - 1] != '+')
	{
		if (!oldkey)
			lst_addback_new_key_value(&data->env, newkey, newvalue);
		else if (newvalue)
			add_val_to_export(data, newkey, newvalue);
	}
	free (newkey);
	free (newvalue);
	return (0);
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
		ret = ft_export_join(cmd, data, i);
		i++;
	}
	data->exit_status = ret;
	return (data->exit_status);
}
