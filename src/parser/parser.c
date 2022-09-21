/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:54:43 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/21 18:32:56 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	parser(t_data *data, char *prompt, t_exec **exec)
{
	t_key_val	*token_list;

	token_list = NULL;
	token_list = lexer(prompt);
	if (token_list == NULL)
		return (-1);
	if (check_syntax_error(token_list) < 0)
	{
		lstclear_key_value(&token_list);
		return (1);
	}
	if (expand_asterisk(token_list))
	{
		lstclear_key_value(&token_list);
		return (1);
	}	
	*exec = pipeline(data, token_list);
	lstclear_key_value(&token_list);
	if (!*exec)
		return (-1);
	if (open_heredoc(data, *exec))
	{
		lstclear_exec(exec);
		return (-1);
	}
	return (0);
}
