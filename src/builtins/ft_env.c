/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:02:20 by refrain           #+#    #+#             */
/*   Updated: 2022/08/29 20:12:29 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int pos_in_envp(t_data *data, char *str)
{
	int	i;

	i = 0;
	while (data->env)
	{
		if (!strcmp(data->env->key, str))
			return (i);
		i++;
		data->env = data->env->next;
	}
	return (-1);
}

int	ft_env(t_data *data)
{
	if (pos_in_envp(data, "PATH") == -1)
	{
		printf("env: No such file or directory");
		return (127);
	}
	while (data->env)
	{
		printf("%s%c%s\n", (char *)data->env->key, '=', (char *)data->env->value);
		data->env = data->env->next;
	}
	return (0);
}
