/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_value_list_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:24:03 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/25 16:37:35 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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

t_key_val	*lstlast_key_value(t_key_val *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

int	lst_size_key_value(t_key_val *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
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

void	lstprint_key_value(t_key_val *lst)
{
	if (!lst)
		return ;
	while (lst)
	{
		printf("%s=%s\n", (char *)lst->key, (char *)lst->value);
		lst = lst->next;
	}
}
