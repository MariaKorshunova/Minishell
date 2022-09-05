/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 03:11:50 by refrain           #+#    #+#             */
/*   Updated: 2022/09/05 18:21:30 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

// int	ft__export(char **cmd, t_data *data)
// {
// 	int		i;
// 	char	**array;

// 	if (!cmd[1])
// 		return (print_env_declare(*data));
// 	while (com->arg[++i])
// 	{
// 		if (check_arg_of_export(com->arg[i]))
// 		{
// 			array = split_for_export(com->arg[i]);
// 			if (!array)
// 				return (1);
// 			add_var_to_envp_list(envp_list, array, com->arg[i]);
// 			free_array(array);
// 		}
// 		else
// 		{
// 			print_export_error(com->arg[i]);
// 			return (1);
// 		}
// 	}
// 	return (0);
// }
