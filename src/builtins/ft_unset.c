/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:43:40 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/19 23:12:28 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_unset(char **cmd, t_key_val **env)
{
	int			i;
	t_key_val	*tmp_env;
	t_key_val	*tmp;

	i = 1;
	if (!*env)
		return (EXIT_SUCCESS);
	while (cmd[i])
	{
		tmp_env = *env;
		if (!ft_strcmp(cmd[i], (char *)tmp_env->key))
		{
			*env = tmp_env->next;
			lstdelone_key_value(tmp_env);
			return (EXIT_SUCCESS);
		}
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
	}
	return (EXIT_SUCCESS);
}
