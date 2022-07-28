/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_spec_symbol_token.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:31:16 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/28 18:41:57 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	add_less_token(t_key_val **token_list, char *prompt, int *i)
{
	if (prompt[*i] == '<')
	{
		if (prompt[*i + 1] == '<')
		{
			if (lstnew_add_back_intkey_value(token_list, DOUBLE_LESS, NULL))
				return (EXIT_FAILURE);
			(*i)++;
		}
		else
		{
			if (lstnew_add_back_intkey_value(token_list, LESS, NULL))
				return (EXIT_FAILURE);
		}
		(*i)++;
	}
	return (EXIT_SUCCESS);
}

int	add_greater_token(t_key_val **token_list, char *prompt, int *i)
{
	if (prompt[*i] == '>')
	{
		if (prompt[*i + 1] == '>')
		{
			if (lstnew_add_back_intkey_value(token_list, DOUBLE_GREATER, NULL))
				return (EXIT_FAILURE);
			(*i)++;
		}
		else
		{
			if (lstnew_add_back_intkey_value(token_list, GREATER, NULL))
				return (EXIT_FAILURE);
		}
		(*i)++;
	}
	return (EXIT_SUCCESS);
}

int	add_pipe_token(t_key_val **token_list, char *prompt, int *i)
{
	if (prompt[*i] == '|')
	{
		if (lstnew_add_back_intkey_value(token_list, PIPE, NULL))
			return (EXIT_FAILURE);
		(*i)++;
	}
	return (EXIT_SUCCESS);
}
