/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:08:34 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/29 18:15:39 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	execution(t_data *data, char *prompt)
{
	t_key_val	*token_list;
	t_list		*pipeline;

	(void) data;
	token_list = NULL;
	pipeline = NULL;
	token_list = lexer(prompt);
	if (token_list == NULL)
		return (EXIT_FAILURE);
	// lstprint_key_value(token_list, 'd');
	if (check_syntax_error(token_list) == -1)
		return (EXIT_FAILURE);
	lstclear_key_value(&token_list);
	return (EXIT_SUCCESS);
}
