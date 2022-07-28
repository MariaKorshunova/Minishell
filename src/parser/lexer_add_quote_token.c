/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_add_quote_token.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 18:21:47 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/28 19:04:26 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_unclosed_quotes(char *prompt, int *i, char c);

int	add_quote_token(t_key_val **token_list, char *prompt, int *i)
{
	int	len;

	len = 0;
	if (prompt[*i] == '\'' || prompt[*i] == '"')
	{
		len = check_unclosed_quotes(prompt, i, prompt[*i]);
		if (len == -1)
			return (EXIT_FAILURE);
	}
	(void)token_list;
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
