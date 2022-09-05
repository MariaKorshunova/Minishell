/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstfunction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:51:34 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/05 16:35:09 by jmabel           ###   ########.fr       */
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

char	**lst_to_chararray(t_list *lst)
{
	char	**arr;
	int		size_arr;
	int		i;

	i = 0;
	size_arr = ft_lstsize(lst);
	arr = (char **)malloc((size_arr + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (i < size_arr)
	{
		arr[i] = strdup((char *)lst->content);
		i++;
		lst = lst->next;
	}
	arr[i] = NULL;
	return (arr);
}
