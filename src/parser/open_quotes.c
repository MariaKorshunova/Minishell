/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:38:29 by jmabel            #+#    #+#             */
/*   Updated: 2022/08/31 19:04:06 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

/* glue consecutive tokens WORD, QUOTE, DOUBLE_QUOTE  with opening quotes.
 Pointer to token_list is moved.
 Pointer can't be NULL */

static int	count_len_word(t_key_val *token);
static int	count_add_envp(char *str);

char	*open_quotes(t_key_val **token)
{
	char	*word;
	int		len;

	(void) word;
	if (token == NULL)
		return (NULL);
	len = count_len_word(*token);
	printf("len=%d\n", len);
	return (NULL);
}

static int	count_len_word(t_key_val *token)
{
	int	len;

	if (token == NULL)
		return (-1);
	len = 0;
	while (*(int *)token->key == WORD || *(int *)token->key == QUOTE
		|| *(int *)token->key == DOUBLE_QUOTE)
	{
		if (*(int *)token->key == QUOTE)
			len += ft_strlen((char *)token->value);
		else
			len += count_add_envp((char *)token->value);
		token = token->next;
		if (token == NULL)
			break ;
	}
	return (len);
}

static int	count_add_envp(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		// if str[i] == '$'
		i++;
	}
	return (i);
}
