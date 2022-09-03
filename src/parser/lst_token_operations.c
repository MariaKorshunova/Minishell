/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_token_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:53:44 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/03 18:16:41 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	add_note_lst_from_token(t_list **expand_token, char *value)
{
	t_list	*lstnew;

	lstnew = NULL;
	lstnew = ft_lstnew(value);
	if (!lstnew)
		return (EXIT_FAILURE);
	ft_lstadd_back(expand_token, lstnew);
	return (EXIT_SUCCESS);
}

int	strdup_str_add_note_lst(t_list **expand_token, char *str)
{
	char	*content;

	content = NULL;
	content = ft_strdup(str);
	if (!content)
		return (EXIT_FAILURE);
	if (add_note_lst_from_token(expand_token, content))
	{
		free(content);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	substr_add_note_lst(t_list **expand_token, char *str, int start, int len)
{
	char	*content;

	content = NULL;
	content = ft_substr(str, start, len);
	if (!content)
		return (EXIT_FAILURE);
	if (add_note_lst_from_token(expand_token, content))
	{
		free(content);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	lst_sum_len_content(t_list *lst)
{
	int	len;

	if (!lst)
		return (-1);
	len = 0;
	while (lst)
	{
		len += ft_strlen((char *)lst->content);
		lst = lst->next;
	}
	return (len);
}
