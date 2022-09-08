/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:02:20 by refrain           #+#    #+#             */
/*   Updated: 2022/09/09 00:50:48 by refrain          ###   ########.fr       */
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
	return (0);
}
