/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_expand_token.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 18:26:30 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/02 18:43:33 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	add_note_expand_tokens(t_key_val *token, t_list **expand_token,
				t_data *data);
static int	add_note_with_expand(char *str, t_list **expand_token,
				t_data *data);
static int	add_note_with_expand_1(char *str, t_list **expand_token,
				t_data *data, int i);

t_list	*expand_tokens(t_key_val *token, t_data *data)
{
	t_list	*expand_token;

	(void) data;
	if (token == NULL)
		return (NULL);
	expand_token = NULL;
	while (*(int *)token->key == WORD || *(int *)token->key == QUOTE
		|| *(int *)token->key == DOUBLE_QUOTE)
	{
		if (add_note_expand_tokens(token, &expand_token, data))
		{
			ft_lstclear(&expand_token, free);
			return (NULL);
		}
		token = token->next;
		if (token == NULL)
			break ;
	}
	return (expand_token);
}

static int	add_note_expand_tokens(t_key_val *token, t_list **expand_token,
					t_data *data)
{
	char	*content;

	content = NULL;
	if (*(int *)token->key == QUOTE)
	{
		if (strdup_str_add_note_lst(expand_token, (char *)token->value))
			return (EXIT_FAILURE);
	}
	else
	{
		if (add_note_with_expand((char *)token->value, expand_token, data))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	add_note_with_expand(char *str, t_list **expand_token, t_data *data)
{
	int		i;

	i = ft_strchr_pos(str, '$');
	if (i == -1)
	{
		if (strdup_str_add_note_lst(expand_token, str))
			return (EXIT_FAILURE);
	}
	else
	{
		if (i > 0)
		{
			if (substr_add_note_lst(expand_token, str, 0, i))
				return (EXIT_FAILURE);
		}
		if (add_note_with_expand_1(str, expand_token, data, i))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	add_note_with_expand_1(char *str, t_list **expand_token,
				t_data *data, int i)
{
	while (str[i] != '\0')
	{
		i++;
		if (str[i] == '\0')
		{
			if (strdup_str_add_note_lst(expand_token, "$"))
				return (EXIT_FAILURE);
			return (EXIT_SUCCESS);
		}
		if (ft_strchr("0$?", str[i]))
		{
			if (add_note_dollar_spec_symbol(str, expand_token, data, &i))
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
