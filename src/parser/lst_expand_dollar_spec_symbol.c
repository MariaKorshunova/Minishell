/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_expand_dollar_spec_symbol.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:42:45 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/03 16:10:46 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	expand_spec_symbol(char *str, t_list **expand_token,
				t_data *data, int i);
static int	expand_spec_symbol_dollar(t_list **expand_token);
static int	expand_spec_symbol_question(t_list **expand_token, t_data *data);

int	add_note_dollar_spec_symbol(char *str, t_list **expand_token,
				t_data *data, int *i)
{
	int		start;
	char	*word;

	start = 0;
	word = NULL;
	if (expand_spec_symbol(str, expand_token, data, *i))
		return (EXIT_FAILURE);
	(*i)++;
	if (str[*i] == '$' || str[*i] == '\0')
		return (EXIT_SUCCESS);
	start = *i;
	while (str[*i] != '$' && str[*i] != '\0')
		(*i)++;
	if (substr_add_note_lst(expand_token, str, start, *i - start))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	expand_spec_symbol(char *str, t_list **expand_token,
				t_data *data, int i)
{
	(void)data;
	if (str[i] == '0')
	{
		if (strdup_str_add_note_lst(expand_token, NAME))
			return (EXIT_FAILURE);
	}
	else if (str[i] == '$')
	{
		if (expand_spec_symbol_dollar(expand_token))
			return (EXIT_FAILURE);
	}
	else if (str[i] == '?')
	{
		if (expand_spec_symbol_question(expand_token, data))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	expand_spec_symbol_dollar(t_list **expand_token)
{
	pid_t	pid;
	char	*pid_str;

	pid = getpid();
	pid_str = ft_itoa((int)pid);
	if (!pid_str)
		return (EXIT_FAILURE);
	if (add_note_lst_from_token(expand_token, pid_str))
	{
		free(pid_str);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	expand_spec_symbol_question(t_list **expand_token, t_data *data)
{
	char	*status;

	status = ft_itoa(data->exit_status);
	if (!status)
		return (EXIT_FAILURE);
	if (add_note_lst_from_token(expand_token, status))
	{
		free(status);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
