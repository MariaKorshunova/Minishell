/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_pipeline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 19:50:51 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/29 22:15:35 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*split_pipeline(t_key_val *token_list)
{
	t_list		*pipeline;
	t_key_val	*token;

	pipeline = NULL;
	token = token_list;
	while (token_list)
	{
		if (*(int *)token_list->key == PIPE)
		{
			printf("%s\n", "pipe!");
		}
		token_list = token_list->next;
	}
	return (pipeline);
}
