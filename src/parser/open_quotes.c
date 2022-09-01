/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:38:29 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/01 18:30:04 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* glue consecutive tokens WORD, QUOTE, DOUBLE_QUOTE  with opening quotes.
 Pointer to token_list is moved.
 Pointer can't be NULL */

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
