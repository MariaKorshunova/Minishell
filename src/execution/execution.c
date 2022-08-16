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

int	execution(t_data *envp, char *prompt)
{
	t_key_val	*token_list;
	t_list		*pipeline;
	t_exec		exec;

	(void)envp;
	token_list = NULL;
	pipeline = NULL;
	token_list = lexer(prompt);
	if (token_list == NULL)
		return (EXIT_FAILURE);
	// lstprint_key_value(token_list, 'd');
	if (check_syntax_error(token_list) == -1)
	{
		printf("%s: %s\n", PREFIX_ERROR, "syntax error near unexpected token `|'");
		return (EXIT_FAILURE);
	}
	lstclear_key_value(&token_list);
	if (executor(&exec, envp))
	{
		printf("Goodbye 🌚");
	}
	return (EXIT_SUCCESS);
}
