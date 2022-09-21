/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 00:15:07 by refrain           #+#    #+#             */
/*   Updated: 2022/09/21 03:26:31 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char	*ft_cut_string(char *str)
{
	int		i;
	char	*newvalue;

	i = ft_strlen(str);
	while (str[i] != '/')
		i--;
	newvalue = ft_substr(str, 0, i + 1);
	if (!newvalue)
		return (NULL);
	return (newvalue);
}

int	ft_check_arg(char **cmd)
{
	int	i;
	int	j;
	int	exit_flag;

	i = 1;
	j = 0;
	while (cmd && cmd[i])
	{
		if ((!ft_isalpha(cmd[i][j]) && cmd[i][j] != '_') ||
			(ft_strchr(cmd[i], '?') || ft_strchr(cmd[i], ':')
			|| ft_strchr(cmd[i], '/') || ft_strchr(cmd[i], '.')
			|| ft_strchr(cmd[i], '*') || ft_strchr(cmd[i], '-')))
		{
			ft_export_unset_print_error(cmd[0], cmd[i],
				"not a valid identifier");
			i++;
			exit_flag = 1;
		}
		else
			return (0);
	}
	if (exit_flag)
		return (1);
	return (0);
}
