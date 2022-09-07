/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:02:20 by refrain           #+#    #+#             */
/*   Updated: 2022/09/07 23:27:02 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_env(t_data *data)
{
	while (data->env)
	{
		printf("%s%c%s\n", (char *)data->env->key, '=',
			(char *)data->env->value);
		data->env = data->env->next;
	}
	// free_2dimensional_array((void **)data->env_arr);
	// free_2dimensional_array((void **)data->bin_path);
	return (0);
}
