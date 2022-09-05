/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_fill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:13:24 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/05 17:14:43 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int		add_redirect(t_data *data, t_key_val **token,
					t_key_val **redirect_list, int key);
static int		add_cmd(t_data *data, t_key_val **token, t_list	**cmd);

int	fill_exec_by_condition(t_data *data, t_key_val **token,
				t_exec *note, t_list **cmd)
{
	if (*(int *)(*token)->key == SEP)
		*token = (*token)->next;
	if (*token == NULL)
		return (EXIT_SUCCESS);
	if (*(int *)(*token)->key == LESS
		|| *(int *)(*token)->key == DOUBLE_LESS)
	{
		if (add_redirect(data, token, &(note->infile), *(int *)(*token)->key))
			return (EXIT_FAILURE);
	}
	else if (*(int *)(*token)->key == GREATER
		|| *(int *)(*token)->key == DOUBLE_GREATER)
	{
		if (add_redirect(data, token, &(note->outfile), *(int *)(*token)->key))
			return (EXIT_FAILURE);
	}
	else if (*(int *)(*token)->key == WORD || *(int *)(*token)->key == QUOTE
				|| *(int *)(*token)->key == DOUBLE_QUOTE)
	{
		if (add_cmd(data, token, cmd))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static	int	add_redirect(t_data *data, t_key_val **token,
							t_key_val **redirect_list, int key)
{
	char	*value;

	value = NULL;
	*token = (*token)->next;
	if (*(int *)(*token)->key == SEP)
		*token = (*token)->next;
	value = expand_dollar(token, data);
	if (!value)
		return (EXIT_FAILURE);
	if (lstnew_add_back_intkey_value(redirect_list, key, (void *)value))
	{
		free(value);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	add_cmd(t_data *data, t_key_val **token, t_list	**cmd)
{
	char	*value;
	t_list	*cmdnew;

	value = NULL;
	if (*(int *)(*token)->key == SEP)
		*token = (*token)->next;
	value = expand_dollar(token, data);
	if (!value)
		return (EXIT_FAILURE);
	cmdnew = ft_lstnew((void *)value);
	if (!cmdnew)
	{
		free(value);
		return (EXIT_FAILURE);
	}
	ft_lstadd_back(cmd, cmdnew);
	return (EXIT_SUCCESS);
}
