/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:01:54 by refrain           #+#    #+#             */
/*   Updated: 2022/09/12 18:01:27 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	ft_remove_env()
{
	
}

int	ft_is_valid()
{
	
}

int	ft_unset(char **cmd, t_data *data)
{
	char	*value;
	int		i;

	i = 1;
	while (cmd && cmd[i])
	{
		value = key_value_search_with_key(data->env, cmd[i]);
		if (value)
		{
			ft_remove_env(cmd[i]);
			free (value);
		}
		if (!ft_is_valid(cmd[i]))
		{
			ft_print_error(cmd[i], "not a valid identifier");
			data->exit_status = 1;
		}
		i++;
	}
	return (data->exit_status);
}
