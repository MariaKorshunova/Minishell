/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 19:50:51 by jmabel            #+#    #+#             */
/*   Updated: 2022/08/01 20:33:44 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_empty_pipeline(t_key_val **token_list);

int	check_syntax_error(t_key_val *token_list)
{
	int			pipe_error;

	if (*(int *)token_list->key == SEP && token_list->next == NULL)
		return (1);
	while (token_list)
	{
		if (*(int *)token_list->key == PIPE)
			return (-1);
		pipe_error = check_empty_pipeline(&token_list);
		if (pipe_error == -1 || pipe_error == 1)
			return (pipe_error);
		pipe_error = -1;
	}
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
		*token_list = (*token_list)->next;
		if (*token_list == NULL)
			return (pipe_error);
	}
	*token_list = (*token_list)->next;
	return (0);
}
