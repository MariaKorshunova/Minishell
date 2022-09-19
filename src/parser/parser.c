/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:54:43 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/16 16:59:39 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_exec	*parser(t_data *data, char *prompt)
{
	t_key_val	*token_list;
	t_exec		*exec;

	token_list = NULL;
	exec = NULL;
	token_list = lexer(prompt);
	if (token_list == NULL)
		return (NULL);
	if (check_syntax_error(token_list) < 0)
	{
		lstclear_key_value(&token_list);
		return (NULL);
	}
	exec = pipeline(data, token_list);
	lstclear_key_value(&token_list);
	if (!exec)
		return (NULL);
	if (open_heredoc(data, exec))
	{
		lstclear_exec(&exec);
		return (NULL);
	}
	return (exec);
}
