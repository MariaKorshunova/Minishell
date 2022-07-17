/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:24:23 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/17 20:56:10 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* in progress. The function have a leak */
void	pars_envp(t_env *list_env, char **envp)
{
	int		i;
	// int		j;
	// char	*name;

	(void)list_env;
	(void)envp;
	i = 0;
	// while (envp[i])
	// {
	// 	j = 0;
	// 	while (envp[i][j] != '=')
	// 		j++;
	// 	// handle error with '=' в envp (j=0 or j=len(str))
	// 	name = ft_substr(envp[i], 0, j);
	// 	printf("%d\t%s\t%s\n", j, name, envp[i++]);
	// }
}

// static void	lstnew_env(char *name, char *content);
