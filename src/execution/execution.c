/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:08:34 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/29 18:15:39 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	execution(t_data *data, char *prompt)
{
	t_exec	*pipeline;

	pipeline = NULL;
	pipeline = parser(data, prompt);
	if (pipeline == NULL)
		return (EXIT_FAILURE);
	print_exec(pipeline);
	lstclear_exec(&pipeline);
	return (EXIT_SUCCESS);
}
