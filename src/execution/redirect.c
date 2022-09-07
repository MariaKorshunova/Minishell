/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:19:22 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/07 18:54:13 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	redicrect_infile(t_data *data, t_key_val *infile)
{
	while (infile)
	{
		if (*(int *)infile->key == LESS)
		{
			if (open_infile(data, (char *)infile->value))
				return (EXIT_FAILURE);
		}
		infile = infile->next;
	}
	return (EXIT_SUCCESS);
}
