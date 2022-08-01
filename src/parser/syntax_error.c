/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 19:50:51 by jmabel            #+#    #+#             */
/*   Updated: 2022/08/01 21:57:34 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_empty_pipeline(t_key_val **token_list);
static void	print_syntax_error(int i);

int	check_syntax_error(t_key_val *token_list)
{
	int			pipe_error;

	if (*(int *)token_list->key == SEP && token_list->next == NULL)
		return (1);
	while (token_list)
	{
		if (*(int *)token_list->key == PIPE)
		{
			print_syntax_error(-1);
			return (-1);
		}
		pipe_error = check_empty_pipeline(&token_list);
		if (pipe_error == -1 || pipe_error == -2 || pipe_error == 1)
		{
			print_syntax_error(pipe_error);
			return (pipe_error);
		}
		pipe_error = -1;
	}
	print_syntax_error(pipe_error);
	return (pipe_error);
}

static int	check_empty_pipeline(t_key_val **token_list)
{
	int	pipe_error;

	pipe_error = -1;
	while (*(int *)(*token_list)->key != PIPE)
	{
		if (pipe_error == -1)
		{
			if (*(int *)(*token_list)->key == SEP)
				*token_list = (*token_list)->next;
			if (*token_list == NULL)
				return (-1);
			if (*(int *)(*token_list)->key == PIPE)
				return (-1);
			pipe_error = 1;
		}
		// Check redirection. In case of error return (-2)
		*token_list = (*token_list)->next;
		if (*token_list == NULL)
			return (pipe_error);
	}
	*token_list = (*token_list)->next;
	return (0);
}

static void	print_syntax_error(int i)
{
	if (i == -1)
		printf("%s: %s\n", PREFIX_ERROR,
			"syntax error near unexpected token `|'");
	else if (i == -2)
		printf("%s: %s\n", PREFIX_ERROR,
			"syntax error near unexpected token `newline'");
}
