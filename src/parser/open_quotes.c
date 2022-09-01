/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:38:29 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/01 13:00:41 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* glue consecutive tokens WORD, QUOTE, DOUBLE_QUOTE  with opening quotes.
 Pointer to token_list is moved.
 Pointer can't be NULL */

static t_list	*expand_tokens(t_key_val *token, t_data *data);
static int		add_note_expand_token(t_list **expand_token, char *value);

char	*open_quotes(t_key_val **token, t_data *data)
{
	t_list	*expand_token;

	if (token == NULL)
		return (NULL);
	expand_token = NULL;
	expand_token = expand_tokens(*token, data);
	if (!expand_token)
		return (NULL);
	lstprint(expand_token, 's');
	ft_lstclear(&expand_token, free);
	return (NULL);
}

static t_list	*expand_tokens(t_key_val *token, t_data *data)
{
	t_list	*expand_token;

	(void) data;
	if (token == NULL)
		return (NULL);
	expand_token = NULL;
	while (*(int *)token->key == WORD || *(int *)token->key == QUOTE
		|| *(int *)token->key == DOUBLE_QUOTE)
	{
		if (*(int *)token->key == QUOTE)
		{
			if (add_note_expand_token(&expand_token, (char *)token->value))
			{
				ft_lstclear(&expand_token, free);
				return (NULL);
			}
		}
		token = token->next;
		if (token == NULL)
			break ;
	}
	return (expand_token);
}

static int	add_note_expand_token(t_list **expand_token, char *value)
{
	t_list	*lstnew;

	lstnew = NULL;
	lstnew = ft_lstnew(value);
	if (!lstnew)
		return (EXIT_FAILURE);
	ft_lstadd_back(expand_token, lstnew);
	return (EXIT_SUCCESS);
}
