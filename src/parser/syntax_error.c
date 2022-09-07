/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 19:50:51 by jmabel            #+#    #+#             */
/*   Updated: 2022/08/31 18:17:59 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_empty_pipeline(t_key_val **token_list);
static int	check_error_redirection(t_key_val **token_list, int *pipe_error);
static int	check_error_redir_unexpected_token(t_key_val *token,
				int *pipe_error);
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
		if (pipe_error != 0)
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
		if (check_error_redirection(token_list, &pipe_error))
			return (pipe_error);
		*token_list = (*token_list)->next;
		if (*token_list == NULL)
			return (pipe_error);
	}
	*token_list = (*token_list)->next;
	return (0);
}

static int	check_error_redirection(t_key_val **token_list, int *pipe_error)
{
	t_key_val	*tmp;

	if (*(int *)(*token_list)->key == GREATER
		|| *(int *)(*token_list)->key == DOUBLE_GREATER
		|| *(int *)(*token_list)->key == LESS
		|| *(int *)(*token_list)->key == DOUBLE_LESS)
	{
		tmp = (*token_list)->next;
		if (tmp == NULL)
		{
			*pipe_error = -2;
			return (EXIT_FAILURE);
		}
		if (*(int *)tmp->key == SEP)
			tmp = tmp->next;
		if (tmp == NULL)
		{
			*pipe_error = -2;
			return (EXIT_FAILURE);
		}
		if (check_error_redir_unexpected_token(tmp, pipe_error))
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}

static int	check_error_redir_unexpected_token(t_key_val *token,
				int *pipe_error)
{
	if (*(int *)token->key == GREATER)
		*pipe_error = -3;
	if (*(int *)token->key == DOUBLE_GREATER)
		*pipe_error = -4;
	if (*(int *)token->key == LESS)
		*pipe_error = -5;
	if (*(int *)token->key == DOUBLE_LESS)
		*pipe_error = -6;
	if (*(int *)token->key == PIPE)
		*pipe_error = -1;
	if (*pipe_error < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static void	print_syntax_error(int i)
{
	if (i == -1)
		printf("%s: %s\n", PREFIX_ERROR,
			"syntax error near unexpected token `|'");
	else if (i == -2)
		printf("%s: %s\n", PREFIX_ERROR,
			"syntax error near unexpected token `newline'");
	else if (i == -3)
		printf("%s: %s\n", PREFIX_ERROR,
			"syntax error near unexpected token `>'");
	else if (i == -4)
		printf("%s: %s\n", PREFIX_ERROR,
			"syntax error near unexpected token `>>'");
	else if (i == -5)
		printf("%s: %s\n", PREFIX_ERROR,
			"syntax error near unexpected token `<'");
	else if (i == -6)
		printf("%s: %s\n", PREFIX_ERROR,
			"syntax error near unexpected token `<<'");
}
