/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_value_lstcreate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 19:22:44 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/05 15:03:55 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_key_val	*lstnew_key_value(void *key, void *value)
{
	t_key_val	*lstnew;

	lstnew = malloc(sizeof(t_key_val));
	if (lstnew == NULL)
		return (NULL);
	lstnew->key = key;
	lstnew->value = value;
	lstnew->next = NULL;
	return (lstnew);
}

void	lstadd_back_key_value(t_key_val **lst, t_key_val *new)
{
	t_key_val	*tmp;

	if (!new || !lst)
		return ;
	tmp = lstlast_key_value(*lst);
	if (tmp)
		tmp->next = new;
	else
		*lst = new;
}

int	lstnew_add_back_intkey_value(t_key_val **lst, int key, void *value)
{
	t_key_val	*lstnew;
	int			*key_pointer;

	lstnew = NULL;
	key_pointer = NULL;
	key_pointer = (int *)malloc(sizeof(int));
	if (!key_pointer)
		return (EXIT_FAILURE);
	*key_pointer = key;
	lstnew = lstnew_key_value(key_pointer, value);
	if (!lstnew)
	{
		free(key_pointer);
		return (EXIT_FAILURE);
	}
	lstadd_back_key_value(lst, lstnew);
	return (EXIT_SUCCESS);
}
