/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:24:23 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/20 19:59:21 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* in progress. The function have a leak */
void	pars_envp(t_key_value *list_env, char **envp)
{
	int			i;
	int			j;
	char		*name;
	char		*value;
	t_key_value	*lstnew;

	(void)list_env;
	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] != '=' && envp[i][j] != '\0')
			j++;
		name = ft_substr(envp[i], 0, j);
		if (envp[i][j] != '\0')
			value = ft_substr(envp[i], j + 1, ft_strlen(envp[i]) - j - 1);
		lstnew = lstnew_key_value(name, value);
		// if (!lstnew)
		free(name);
		free(value);
		// printf("%s=%s\n", lstnew->key, lstnew->value);
		// printf("%s=%s\n", name, value);
		// printf("%s\n", envp[i]);
		i++;
	}
}
