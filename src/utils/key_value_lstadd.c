/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_value_lstadd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:00:49 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/19 21:29:53 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_key_val	*create_lstnew(char *newkey, char *value);

int	lst_addback_new_key_value(t_key_val **lst, char *key, char *value)
{
	t_key_val	*lstnew;
	char		*newkey;

	newkey = ft_strdup(key);
	if (!newkey)
		return (EXIT_FAILURE);
	lstnew = create_lstnew(newkey, value);
	if (!lstnew)
	{
		free(newkey);
		return (EXIT_FAILURE);
	}
	lstadd_back_key_value(lst, lstnew);
	return (EXIT_SUCCESS);
}

static t_key_val	*create_lstnew(char *newkey, char *value)
{
	t_key_val	*lstnew;
	char		*newvalue;

	if (!value)
		lstnew = lstnew_key_value(newkey, value);
	else
	{
		newvalue = ft_strdup(value);
		if (!newvalue)
			return (NULL);
		lstnew = lstnew_key_value(newkey, newvalue);
		if (!lstnew)
			free(newvalue);
	}
	return (lstnew);
}
