/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 00:15:07 by refrain           #+#    #+#             */
/*   Updated: 2022/09/14 17:42:31 by refrain          ###   ########.fr       */
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

// void	ft_print_builtin_error(char *name, char *str_error)
// {
// 	ft_putstr_fd(PREFIX_ERROR, 2);
// 	if (name)
// 	{
// 		ft_putstr_fd(": ", 2);
// 		ft_putstr_fd(name, 2);
// 	}
// 	ft_putstr_fd(": ", 2);
// 	ft_putstr_fd(str_error, 2);
// 	ft_putstr_fd("\n", 2);
// }