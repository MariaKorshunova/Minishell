/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstprint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:51:34 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/01 12:58:57 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lstprint(t_list *lst, char c)
{
	if (!lst)
		return ;
	while (lst)
	{
		if (c == 's')
			printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
}
