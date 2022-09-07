/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:02:43 by refrain           #+#    #+#             */
/*   Updated: 2022/09/07 18:13:41 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	ft_negative_number(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[1][++i])
	{
		if (cmd[1][i] < '0' || cmd[1][i] > '9')
		{
			ft_print_error(cmd[1], ":numeric argument required");
			free_2dimensional_array((void **)cmd);
			exit (255);
		}
	}
	if (cmd[2])
		ft_print_error(cmd[0], "too many arguments");
	else
	{
		i = ft_atoi(cmd[1]);
		i = 256 + i;
		printf("exit\n");
		printf("your number is %d\n", i);
		free_2dimensional_array((void **)cmd);
		exit (i);
	}
}

void	ft_exit_util(char **cmd)
{
	int	i;

	i = 0;
	if (cmd[1][i] == '+')
		i++;
	if (cmd[1][i] == '-')
		ft_negative_number(cmd);
	while (cmd[1][++i])
	{
		if (cmd[1][i] < '0' || cmd[1][i] > '9')
		{
			ft_print_error(cmd[1], ":numeric argument required");
			free_2dimensional_array((void **)cmd);
			exit (255);
		}
	}
	if (cmd[2])
		ft_print_error(cmd[0], "too many arguments");
	else
	{
		i = ft_atoi(cmd[1]);
		printf("exit\n");
		free_2dimensional_array((void **)cmd);
		exit (i);
	}
}

void	ft_exit(char **cmd)
{
	if (!cmd[1])
	{
		printf("exit\n");
		free_2dimensional_array((void **)cmd);
		exit (0);
	}
	else
		ft_exit_util(cmd);
}
