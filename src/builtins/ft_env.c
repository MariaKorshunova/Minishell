/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:02:20 by refrain           #+#    #+#             */
/*   Updated: 2022/09/15 23:50:05 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_env(t_data *data)
{
	t_key_val	*temp;

	temp = data->env;
	while (temp)
	{
		printf("%s%c%s\n", (char *)temp->key, '=',
			(char *)temp->value);
		temp = temp->next;
	}
	data->exit_status = 0;
	return (data->exit_status);
}
