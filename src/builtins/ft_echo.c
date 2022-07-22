/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:58:46 by refrain           #+#    #+#             */
/*   Updated: 2022/07/22 20:54:14 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

void	find_builtin(char **cmd)
{
	if (ft_strncmp((*cmd)[0], "echo", 4 == 0))
		ft_echo(cmd);
}

int	ft_echo(char **cmd)
{
	int		i;
	char	**str;

	i = 0;
	while (cmd[i])
		str[++i] = cmd[++i];
	if (ft_strncmp(str, "echo", 4) == 0 && cmd[i] != '\0')
	{
		i++;
		while (cmd[i])
			printf("%c", cmd[i++]);
	}
	else
		return (1);
	return (0);
}
