/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:54:43 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/01 11:44:11 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// static t_list	*parser_pipeline(t_key_val *token_list);

t_list	*parser(t_data *data, char *prompt)
{
	t_list		*pipeline;
	t_key_val	*token_list;

	pipeline = NULL;
	token_list = NULL;
	token_list = lexer(prompt);
	if (token_list == NULL)
		return (NULL);
	if (check_syntax_error(token_list) < 0)
	{
		lstclear_key_value(&token_list);
		return (NULL);
	}
	lstprint_key_value(token_list, 'd');
	open_quotes(&token_list, data);
	// lstprint_key_value(token_list, 'd');
	// pipeline = parser_pipeline(token_list);
	lstclear_key_value(&token_list);
	return (pipeline);
}

// static t_list	*parser_pipeline(t_key_val *token_list)
// {
// 	t_list	*pipeline;

// 	pipeline = NULL;
// 	while (token_list)
// 	{
// 		if (add_lst_pipeline(token_list))
// 			return (EXIT_FAILURE);
// 		token_list = token_list->next;
// 	}
// 	return (pipeline);
// }

/*
		if (*(int *)token_list->key == WORD
			|| *(int *)token_list->key == QUOTE
			|| *(int *)token_list->key == DOUBLE_QUOTE)
*/