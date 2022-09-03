/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_value_search_with_key.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:33:02 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/03 17:58:35 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*key_value_search_with_key(t_key_val *env, char	*key)
{
	int	len_key;

	len_key = ft_strlen(key);
	while (env)
	{
		if (!ft_strncmp(key, (char *)env->key, len_key))
		{
			return ((char *)env->value);
			break ;
		}
		env = env->next;
	}
	return (NULL);
}
