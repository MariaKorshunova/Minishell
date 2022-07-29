/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_add_quote_token.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:21:47 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/29 16:44:41 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_unclosed_quotes(char *prompt, int *i, char c);
static int	add_single_quote_token(t_key_val **token_list, char *prompt, int *i,
				int len);
static int	add_double_quote_token(t_key_val **token_list, char *prompt, int *i,
				int len);

int	add_quotes_token(t_key_val **token_list, char *prompt, int *i)
{
	int	len;

	len = 0;
	if (prompt[*i] == '\'' || prompt[*i] == '"')
	{
		len = check_unclosed_quotes(prompt, i, prompt[*i]);
		if (len == -1)
			return (EXIT_FAILURE);
		if (prompt[*i] == '\'')
		{
			if (add_single_quote_token(token_list, prompt, i, len))
				return (EXIT_FAILURE);
		}
		else if (prompt[*i] == '"')
		{
			if (add_double_quote_token(token_list, prompt, i, len))
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

static int	check_unclosed_quotes(char *prompt, int *i, char c)
{
	int	len;

	len = 1;
	while (prompt[*i + len] != '\0' && prompt[*i + len] != c)
		len++;
	if (prompt[*i + len] == '\0')
	{
		printf("%s: %s\n", PREFIX_ERROR, "syntax error: unclosed quotes");
		return (-1);
	}
	return (len);
}

static int	add_single_quote_token(t_key_val **token_list, char *prompt, int *i,
				int len)
{
	char	*value;

	value = NULL;
	value = ft_substr(prompt, *i + 1, len - 1);
	if (!value)
		return (EXIT_FAILURE);
	if (lstnew_add_back_intkey_value(token_list, QUOTE, value))
	{
		free(value);
		return (EXIT_FAILURE);
	}
	(*i) += len + 1;
	return (EXIT_SUCCESS);
}

static int	add_double_quote_token(t_key_val **token_list, char *prompt, int *i,
				int len)
{
	char	*value;

	value = NULL;
	value = ft_substr(prompt, *i + 1, len - 1);
	if (!value)
		return (EXIT_FAILURE);
	if (lstnew_add_back_intkey_value(token_list, DOUBLE_QUOTE, value))
	{
		free(value);
		return (EXIT_FAILURE);
	}
	(*i) += len + 1;
	return (EXIT_SUCCESS);
}
