/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_lstcreate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 20:20:25 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/03 20:33:48 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_exec	*lstnew_exec(char **cmd, t_key_val *infile, t_key_val *outfile)
{
	t_exec	*lstnew;

	lstnew = malloc(sizeof(t_exec));
	if (!lstnew)
		return (NULL);
	lstnew->cmd = cmd;
	lstnew->infile = infile;
	lstnew->outfile = outfile;
	lstnew->next = NULL;
	return (lstnew);
}

void	lstadd_back_exec(t_exec **lst, t_exec *new)
{
	t_exec	*tmp;

	if (!new || !lst)
		return ;
	tmp = lstlast_exec(*lst);
	if (tmp)
		tmp->next = new;
	else
		*lst = new;
}
