/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:08:34 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/27 17:12:50 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	lexer_parser(t_data *data, char *prompt)
{
	t_key_val	*token_list;

	(void) data;
	token_list = NULL;
	token_list = lexer(prompt);
	lstprint_key_value(token_list, 'd');
	lstclear_key_value(&token_list);
	return (EXIT_SUCCESS);
}
