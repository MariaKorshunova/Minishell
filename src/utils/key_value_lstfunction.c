/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_value_lstfunction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:24:03 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/03 18:11:23 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

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

void	lstprint_key_value(t_key_val *lst, char type)
{
	if (!lst)
		return ;
	while (lst)
	{
		if (type == 's')
			printf("%s=%s\n", (char *)lst->key, (char *)lst->value);
		else if (type == 'd')
			printf("%d=%s\n", *(int *)lst->key, (char *)lst->value);
		lst = lst->next;
	}
}
