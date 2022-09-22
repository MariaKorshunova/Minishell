/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:39:55 by refrain           #+#    #+#             */
/*   Updated: 2022/09/21 17:41:55 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char	*find_new_value(char **cmd, char *newkey, int i)
{
	int		j;
	char	*newvalue;

	j = 0;
	while (cmd[i][j] != '=' && cmd[i][j] != '\0')
		j++;
	if (cmd[i][j] == '\0')
		newvalue = NULL;
	else
	{
		newvalue = ft_substr(cmd[i], j + 1, ft_strlen(cmd[i]) - j - 1);
		if (!newvalue)
		{
			free (newkey);
			return (NULL);
		}	
	}
	return (newvalue);
}

char	*find_new_key(char **cmd, int i)
{
	int		j;
	char	*newkey;

	j = 0;
	while (cmd[i][j] != '=' && cmd[i][j] != '\0')
		j++;
	newkey = ft_substr(cmd[i], 0, j);
	if (!newkey)
		return (NULL);
	return (newkey);
}

char	*find_key(t_key_val *env, char	*key)
{
	while (env)
	{
		if (!ft_strcmp(key, (char *)env->key))
		{
			return ((char *)env->key);
			break ;
		}
		env = env->next;
	}
	return (NULL);
}
