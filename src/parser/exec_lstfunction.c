/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_lstfunction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 20:30:22 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/03 20:32:03 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_exec	*lstlast_exec(t_exec *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
