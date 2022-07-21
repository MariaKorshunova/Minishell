/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:24:23 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/21 21:09:05 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* in progress */
int	pars_envp(t_key_val **lst_env, char **envp)
{
	int			i;
	int			j;
	char		*name;
	char		*value;
	t_key_val	*lstnew;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] != '=' && envp[i][j] != '\0')
			j++;
		name = ft_substr(envp[i], 0, j);
		if (!name)
			return (EXIT_FAILURE);
		if (envp[i][j] != '\0')
		{
			value = ft_substr(envp[i], j + 1, ft_strlen(envp[i]) - j - 1);
			if (!value)
			{
				free(name);
				return (EXIT_FAILURE);
			}
		}
		lstnew = lstnew_key_value(name, value);
		lstadd_back_key_value(lst_env, lstnew);
		i++;
	}
	lstprint_key_value(*lst_env);
	return (EXIT_SUCCESS);
}
