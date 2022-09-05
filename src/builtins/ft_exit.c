/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:02:43 by refrain           #+#    #+#             */
/*   Updated: 2022/09/01 19:57:55 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	ft_exit_util(char **cmd)
{
	int	i;

	i = 0;
	if (cmd[1][i] == '+' || cmd[1][i] == '-')
		i++;
	while (cmd[1][++i])
	{
		if (cmd[1][i] < '0' || cmd[1][i] > '9')
		{
			printf("bash: exit: numeric argument required");
			free_2dimensional_array((void **)cmd);
			exit(255);
		}
	}
	if (cmd[2])
		printf("bash: exit: too many arguments");
	else
	{
		i = ft_atoi(cmd[1]);
		printf("exit\n");
		free_2dimensional_array((void **)cmd);
		exit (i);
	}
}

void	ft_exit(char ** cmd)
{
	int	i;

	i = 0;
	if (!cmd[1])
	{
		printf("exit\n");
		free_2dimensional_array((void **)cmd);
		exit (0);
	}
	else
		ft_exit_util(cmd);
}

// char	**ft_example(void)
// {
// 	char	**str;

// 	str = (char **)malloc (3 * sizeof(char *));
// 	str[0] = ft_strdup("exit");
// 	str[1] = ft_strdup("d");
// 	str[2] = NULL;
// 	// str[3] = ft_strdup("-n");
// 	return (str);
// }
