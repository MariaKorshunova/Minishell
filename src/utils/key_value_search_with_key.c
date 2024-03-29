/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_value_search_with_key.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:33:02 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/05 22:25:00 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*key_value_search_with_key(t_key_val *env, char	*key)
{
	while (env)
	{
		if (!ft_strcmp(key, (char *)env->key))
		{
			return ((char *)env->value);
			break ;
		}
		env = env->next;
	}
	return (NULL);
}
