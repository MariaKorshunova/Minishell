/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_asterisk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:33:30 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/21 19:31:44 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	expand_asterisk(t_key_val *token_list)
{
	struct dirent	*dir;

	while (token_list)
	{
		if (*(int *)token_list->key == WORD)
		{
			if (((char *)token_list->value)[0] == '*')
			{
				dir = readdir(getcwd());
				if (((char *)token_list->value)[1] == '\0')
					printf("%s\n", (char *)token_list->value);
			}
		}
		token_list = token_list->next;
	}
	return (EXIT_SUCCESS);
}