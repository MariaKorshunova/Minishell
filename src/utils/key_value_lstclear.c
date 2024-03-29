/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_value_lstclear.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:30:57 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/19 19:25:02 by refrain          ###   ########.fr       */
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

	if (!lst)
		return ;
	if (!(*lst))
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		lstdelone_key_value(tmp);
	}
}
