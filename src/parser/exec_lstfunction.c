/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_lstfunction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 20:30:22 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/05 17:08:44 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_exec	*lstlast_exec(t_exec *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	print_exec(t_exec *exec)
{
	int	i;

	i = 1;
	while (exec)
	{
		printf("\e[0;33mpipeline %d\e[0m\n", i);
		printf("\e[0;34mCOMMAND\e[0m\n");
		print_2dimensional_chararray(exec->cmd);
		printf("\e[0;34mINFILE\e[0m\n");
		lstprint_key_value(exec->infile, 'd');
		printf("\e[0;34mOUTFILE\e[0m\n");
		lstprint_key_value(exec->outfile, 'd');
		exec = exec->next;
		i++;
	}
}
