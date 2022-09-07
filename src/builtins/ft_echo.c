/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:58:46 by refrain           #+#    #+#             */
/*   Updated: 2022/09/07 20:19:38 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	check_max_index(char **cmd)
{
	int	index;

	index = 0;
	while (cmd[index])
		index++;
	return (index);
}

void	print_cmd(char **cmd, int i)
{
	int	index;

	index = check_max_index(cmd);
	while (cmd && cmd[i])
	{
		if (ft_strcmp(cmd[i], "-n") == 0)
			i++;
		else
		{
			printf("%s%c", cmd[i++], 32);
			while (cmd && cmd[i])
			{
				printf("%s", cmd[i++]);
				if (i != index)
					printf("%c", 32);
			}
		}
	}
}

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
	print_cmd(cmd, i);
	if (flag == 0)
		printf("\n");
	return (0);
}
