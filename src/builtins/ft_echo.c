/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:58:46 by refrain           #+#    #+#             */
/*   Updated: 2022/09/07 02:00:28 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_echo(char **cmd)
{
	int		i;
	int		flag;

	i = 1;
	flag = 0;
	if (cmd[i] && ft_strcmp(cmd[i], "-n") == 0)
	{
		flag = 1;
		i = 2;
	}
	while (cmd && cmd[i])
	{
		if (ft_strcmp(cmd[i], "-n") == 0)
			i++;
		else
		{
			printf("%s%c", cmd[i++], 32);
			while (cmd && cmd[i])
				printf("%s%c", cmd[i++], 32);
		}
	}
	if (flag == 0)
		printf("\n");
	exit (0);
}
