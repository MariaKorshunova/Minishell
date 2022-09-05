/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:38:29 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/05 13:18:12 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* glue consecutive tokens WORD, QUOTE, DOUBLE_QUOTE  with opening quotes.
 Pointer to token_list is moved.
 Pointer can't be NULL */

static char	*expand_token_to_char(t_list *expand_token);

char	*expand_dollar(t_key_val **token, t_data *data)
{
	t_list	*expand_token;
	char	*expand;

	if (token == NULL)
		return (NULL);
	expand_token = NULL;
	expand = NULL;
	expand_token = expand_tokens(token, data);
	if (!expand_token)
		return (NULL);
	expand = expand_token_to_char(expand_token);
	ft_lstclear(&expand_token, free);
	return (expand);
}

static char	*expand_token_to_char(t_list *expand_token)
{
	char	*expand;
	int		len;
	int		i;
	int		j;

	expand = NULL;
	if (!expand_token)
		return (NULL);
	i = 0;
	len = lst_sum_len_content(expand_token);
	expand = (char *)malloc((len + 1) * sizeof(char));
	if (!expand)
		return (NULL);
	while (expand_token)
	{
		j = 0;
		while (((char *)expand_token->content)[j] != '\0')
			expand[i++] = ((char *)expand_token->content)[j++];
		expand_token = expand_token->next;
	}
	expand[i] = '\0';
	return (expand);
}
