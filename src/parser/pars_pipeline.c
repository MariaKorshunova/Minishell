/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:23:04 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/05 17:23:45 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int		add_note_exec(t_data *data, t_exec **exec, t_key_val **token);
static int		add_to_exec(t_exec **exec, t_exec **note_exec,
					t_list **cmd_list);

t_exec	*pipeline(t_data *data, t_key_val *token)
{
	t_exec		*exec;

	if (!token)
		return (NULL);
	exec = NULL;
	while (token)
	{
		if (add_note_exec(data, &exec, &token))
		{
			lstclear_exec(&exec);
			return (NULL);
		}
		if (token == NULL)
			break ;
		else
			token = token->next;
	}
	return (exec);
}

static int	add_note_exec(t_data *data, t_exec **exec, t_key_val **token)
{
	t_exec		*note_exec;
	t_list		*cmd;

	cmd = NULL;
	note_exec = NULL;
	note_exec = lstnew_exec(NULL, NULL, NULL);
	if (!note_exec)
		return (EXIT_FAILURE);
	while (*(int *)(*token)->key != PIPE)
	{
		if (fill_exec_by_condition(data, token, note_exec, &cmd))
		{
			lstclear_exec(&note_exec);
			ft_lstclear(&cmd, free);
			return (EXIT_FAILURE);
		}
		if (*token == NULL)
			break ;
	}
	if (add_to_exec(exec, &note_exec, &cmd))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	add_to_exec(t_exec **exec, t_exec **note_exec, t_list **cmd_list)
{
	(*note_exec)->cmd = lst_to_chararray(*cmd_list);
	ft_lstclear(cmd_list, free);
	if (!(*note_exec)->cmd)
	{
		lstclear_exec(note_exec);
		return (EXIT_FAILURE);
	}
	lstadd_back_exec(exec, *note_exec);
	return (EXIT_SUCCESS);
}
