/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:24:23 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/05 21:08:10 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			pars_envp(t_data *data, char **envp);

int	pars_envp(t_data *data, char **envp)
{
	if (pars_envp_lst(&data->env, envp))
	{
		perror(PREFIX_ERROR);
		return (EXIT_FAILURE);
	}
	if (envp_list_to_chararray(data))
	{
		lstclear_key_value(&data->env);
		perror(PREFIX_ERROR);
		return (EXIT_FAILURE);
	}
	if (ft_get_path(data))
	{
		lstclear_key_value(&data->env);
		free_2dimensional_array((void **)data->env_arr);
		perror(PREFIX_ERROR);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_get_path(t_data *data)
{
	char	*path;

	path = NULL;
	path = key_value_search_with_key(data->env, "PATH");
	data->bin_path = ft_split(path, ':');
	if (!data->bin_path)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
