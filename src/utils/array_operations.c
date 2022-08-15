/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:18:29 by jmabel            #+#    #+#             */
/*   Updated: 2022/08/15 02:21:00 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_2dimensional_array(void **arr)
{
	int	i;

	if (!(arr))
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	print_2dimensional_chararray(char **arr)
{
	int	i;

	if (!(arr))
		return ;
	i = 0;
	while (arr[i])
		printf("%s\n", arr[i++]);
}
