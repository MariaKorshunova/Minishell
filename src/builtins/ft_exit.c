/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:02:43 by refrain           #+#    #+#             */
/*   Updated: 2022/09/14 15:02:17 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_isnumeric(char **cmd, t_data *data)
{
	int	i;

	i = 0;
	if (cmd[1][i] == '+' || (cmd[1][i] == '-'))
		i++;
	while (cmd[1][i])
	{
		if (cmd[1][i] < '0' || cmd[1][i] > '9')
		{
			ft_print_error(cmd[1], ":numeric argument required");
			data->exit_status = 255;
			return (data->exit_status);
		}
		++i;
	}
	return (0);
}

int	ft_check_number(int i)
{
	if (i >= 256)
		i = i % 256;
	else if (i < -256)
	{
		while (i < -256)
		{
			i = i % 256;
			if (i == 0)
				return (i);
		}
		i = 256 + i;
	}
	else if (i < 0 && i >= -256)
	{
		i = 256 + i;
	}
	return (i);
}

int	ft_negative_number(char **cmd, t_data *data)
{
	int	i;

	i = ft_isnumeric(cmd, data);
	if (cmd[2])
	{
		ft_print_error(cmd[0], "too many arguments");
		data->exit_status = 1;
		return (data->exit_status);
	}
	else
	{
		i = ft_atoi(cmd[1]);
		i = ft_check_number(i);
		printf("exit\n");
		data->exit_flag = 0;
		data->exit_status = i;
		return (data->exit_status);
	}
	return (data->exit_status);
}

int	ft_exit_util(char **cmd, t_data *data)
{
	int	i;

	i = 0;
	if (cmd[1][i] == '+')
		i++;
	if (cmd[1][i] == '-')
		return (ft_negative_number(cmd, data));
	i = ft_isnumeric(cmd, data);
	if (cmd[2])
	{
		ft_print_error(cmd[0], "too many arguments");
		data->exit_status = 1;
		return (data->exit_status);
	}
	else
	{
		i = ft_atoi(cmd[1]);
		i = ft_check_number(i);
		printf("exit\n");
		data->exit_flag = 0;
		data->exit_status = i;
		return (data->exit_status);
	}
	return (0);
}

int	ft_exit(char **cmd, t_data *data)
{
	if (!cmd[1])
	{
		printf("exit\n");
		data->exit_flag = 0;
		data->exit_status = 0;
		return (data->exit_status);
	}
	else
		return (ft_exit_util(cmd, data));
}
