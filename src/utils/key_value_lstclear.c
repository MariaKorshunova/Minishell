/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_value_lstclear.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:30:57 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/21 20:39:20 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lstdelone_key_value(t_key_val *lst)
{
	if (!lst)
		return ;
	free(lst->key);
	free(lst->value);
	free(lst);
}

void	lstclear_key_value(t_key_val **lst)
{
	t_key_val	*tmp;

	if (!(*lst))
		return ;
	while (*lst)
	{
		tmp = *lst;
		lstdelone_key_value(tmp);
		*lst = (*lst)->next;
	}
}
