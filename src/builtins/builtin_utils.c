/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 00:15:07 by refrain           #+#    #+#             */
/*   Updated: 2022/09/19 20:27:37 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char	*ft_cut_string(char *str)
{
	int		i;
	char	*newvalue;

	i = ft_strlen(str);
	while (str[i] != '/')
		i--;
	newvalue = ft_substr(str, 0, i + 1);
	if (!newvalue)
		return (NULL);
	return (newvalue);
}

t_key_val	*lst_builtins_new_key_value(char *key, char *value)
{
	t_key_val	*lstnew;
	char		*newkey;
	char		*newvalue;

	newkey = ft_strdup(key);
	if (!newkey)
		return (NULL);
	newvalue = ft_strdup(value);
	if (!newvalue)
		return (NULL);
	lstnew = malloc(sizeof(t_key_val));
	if (!lstnew)
		return (NULL);
	lstnew->key = newkey;
	lstnew->value = newvalue;
	lstnew->next = NULL;
	if (!lstnew)
	{
		free(newkey);
		free(newvalue);
		return (NULL);
	}
	return (lstnew);
}

int	lst_addback_new_key_value(t_key_val **lst, char *key, char *value)
{
	t_key_val	*lstnew;

	lstnew = lst_builtins_new_key_value(key, value);
	if (!lstnew)
		return (EXIT_FAILURE);
	lstadd_back_key_value(lst, lstnew);
	return (EXIT_SUCCESS);
}
