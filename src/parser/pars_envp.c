/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:24:23 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/21 16:07:54 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	pars_envp(t_data *data, char **envp)
{
	if (pars_envp_lst(&data->env, envp))
		return (EXIT_FAILURE);
	if (change_init_env(&data->env))
	{
		lstclear_key_value(&data->env);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_get_path(t_data *data)
{
	char	*path;

	free_2dimensional_array((void **)data->bin_path);
	path = NULL;
	path = key_value_search_with_key(data->env, "PATH");
	if (!path)
	{
		data->bin_path = NULL;
		return (EXIT_SUCCESS);
	}
	data->bin_path = ft_split(path, ':');
	if (!data->bin_path)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
