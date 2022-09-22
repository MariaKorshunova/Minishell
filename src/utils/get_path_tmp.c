/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_tmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:07:51 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/14 14:51:58 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_path_tmp(t_data *data)
{
	char	*path_tmp;
	char	*value_tmp;
	int		i;

	i = 0;
	path_tmp = NULL;
	while (data->key_tmp[i])
	{
		value_tmp = key_value_search_with_key(data->env, data->key_tmp[i++]);
		if (value_tmp)
		{
			if (ft_strrchr_pos(value_tmp, '/') != (int)ft_strlen(value_tmp) - 1)
				path_tmp = ft_strjoin(value_tmp, "/");
			else
				path_tmp = ft_strdup(value_tmp);
			if (!path_tmp)
				return (NULL);
			break ;
		}
	}
	if (!path_tmp)
		path_tmp = ft_strdup("");
	if (!path_tmp)
		return (NULL);
	return (path_tmp);
}
