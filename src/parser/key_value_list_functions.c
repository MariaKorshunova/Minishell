/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_value_list_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:24:03 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/20 17:29:51 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_key_value	*lstnew_key_value(void *key, void *value)
{
	t_key_value	*lstnew;

	lstnew = malloc(sizeof(t_key_value));
	if (lstnew == NULL)
		return (NULL);
	lstnew->key = key;
	lstnew->value = value;
	return (lstnew);
}

void	lstadd_back_key_value(t_key_value **lst, t_key_value *new)
{
	t_key_value	*tmp;

	if (!new || !lst)
		return ;
	while (*lst && (*lst)->next)
		tmp = (*lst)->next;
	if (tmp)
		tmp->next = new;
	else
		*lst = new;
}
