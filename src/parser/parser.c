/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:54:43 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/03 20:54:05 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_exec	*pipeline(t_data *data, t_key_val *token);
// static int		add_note_exec(t_exec **exec, t_data *data, t_key_val **token);

t_exec	*parser(t_data *data, char *prompt)
{
	t_key_val	*token_list;
	t_exec		*exec;
	char		*check;

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
	lstprint_key_value(token_list, 'd');
	check = open_quotes(&token_list, data);
	printf("check%s\n", check);
	free(check);
	lstprint_key_value(token_list, 'd');
	exec = pipeline(data, token_list);
	lstclear_key_value(&token_list);
	return (exec);
}

static t_exec	*pipeline(t_data *data, t_key_val *token)
{
	t_exec		*exec;

	(void) data;
	if (!token)
		return (NULL);
	exec = NULL;
	while (token)
	{
		if (*(int *)token->key == PIPE)
			token = token->next;
		while (*(int *)token->key != PIPE)
		{
			// if (add_note_exec(&exec, data, &token))
			// {
			// 	lstclear_exec(&exec);
			// 	return (NULL);
			// }
			token = token->next;
			if (token == NULL)
				break ;
		}
	}
	return (exec);
}

// static int	add_note_exec(t_exec **exec, t_data *data, t_key_val **token)
// {
// 	return (EXIT_SUCCESS);
// }

/* 	t_list		*cmd;
	t_key_val	*infile;
	t_key_val	*outfile; */

/* 	cmd = NULL;
	infile = NULL;
	outfile = NULL; */

/* open_quotes(&token_list, data); */