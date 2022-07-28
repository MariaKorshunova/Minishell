/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:59:29 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/28 15:15:23 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	add_sep_token(t_key_val **token_list, char *prompt, int *i);
static int	add_word_token(t_key_val **token_list, char *prompt, int *i);

t_key_val	*lexer(char *prompt)
{
	int			i;
	int			len_prompt;
	t_key_val	*token_list;

	i = 0;
	len_prompt = (int)ft_strlen(prompt);
	token_list = NULL;
	while (i < len_prompt)
	{
		if (add_sep_token(&token_list, prompt, &i))
		{
			lstclear_key_value(&token_list);
			return (NULL);
		}
		if (add_word_token(&token_list, prompt, &i))
		{
			lstclear_key_value(&token_list);
			return (NULL);
		}
		if (ft_strchr(SPEC_SYMBOL, prompt[i]) != NULL)
			i++;
	}
	return (token_list);
}

static int	add_sep_token(t_key_val **token_list, char *prompt, int *i)
{
	int			j;

	j = *i;
	while (ft_strchr(SEPARATOR, prompt[*i]) != NULL)
		(*i)++;
	if (j != *i)
	{
		if (lstnew_add_back_intkey_value(token_list, SEP, NULL))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	add_word_token(t_key_val **token_list, char *prompt, int *i)
{
	int			j;
	char		*value;

	j = *i;
	value = NULL;
	while (ft_strchr(SPEC_SYMBOL, prompt[*i]) == NULL
		&& ft_strchr(SEPARATOR, prompt[*i]) == NULL)
		(*i)++;
	if (j != *i)
	{
		value = ft_substr(prompt, j, *i - j);
		if (!value)
			return (EXIT_FAILURE);
		if (lstnew_add_back_intkey_value(token_list, WORD, value))
		{
			free(value);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
