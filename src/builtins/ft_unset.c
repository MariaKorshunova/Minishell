/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:43:40 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/21 03:02:19 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	ft_unset_del_env(char **cmd, t_key_val **env, int i)
{
	t_key_val	*tmp_env;

	tmp_env = *env;
	if (!ft_strcmp(cmd[i], (char *)tmp_env->key))
	{
		*env = tmp_env->next;
		lstdelone_key_value(tmp_env);
		return (EXIT_SUCCESS);
	}
	i++;
	return (EXIT_SUCCESS);
}

static int	ft_unset_util(char **cmd, t_key_val **env, int i)
{
	t_key_val	*tmp_env;
	t_key_val	*tmp;

	tmp_env = *env;
	while (tmp_env->next)
	{
		if (!ft_strcmp(cmd[i], (char *)tmp_env->next->key))
		{
			tmp = tmp_env->next;
			tmp_env->next = tmp_env->next->next;
			lstdelone_key_value(tmp);
			return (EXIT_SUCCESS);
		}
		tmp_env = tmp_env->next;
	}
	i++;
	return (EXIT_SUCCESS);
}

int	ft_unset(char **cmd, t_data *data)
{
	int			i;

	i = 1;
	if (!data->env)
		return (EXIT_SUCCESS);
	if (ft_check_arg(cmd))
	{
		data->exit_status = 1;
		return (data->exit_status);
	}
	while (cmd && cmd[i])
	{
		ft_unset_del_env(cmd, &data->env, i);
		ft_unset_util(cmd, &data->env, i);
		i++;
	}
	data->exit_status = 0;
	return (data->exit_status);
}
