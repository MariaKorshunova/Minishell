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
	t_list	*pipeline;

	(void) data;
	pipeline = NULL;
	pipeline = parser(prompt);
	if (pipeline == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}