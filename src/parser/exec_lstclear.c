/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_lstclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 20:35:10 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/03 20:43:10 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lstdelone_exec(t_exec *lst)
{
	if (!lst)
		return ;
	free_2dimensional_array((void **)(lst->cmd));
	lstclear_key_value(&(lst->infile));
	lstclear_key_value(&(lst->outfile));
	free(lst);
}

void	lstclear_exec(t_exec **lst)
{
	t_exec	*tmp;

	if (!lst)
		return ;
	if (!(*lst))
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		lstdelone_exec(tmp);
	}
}
