/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:18:09 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/18 03:00:51 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	ft_print_error(char *name, char *str_error)
{
	ft_putstr_fd(PREFIX_ERROR, 2);
	if (name)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(name, 2);
	}
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(str_error, 2);
	ft_putstr_fd("\n", 2);
}

void	ft_error_child_process(t_data *data, t_exec **pipeline)
{
	destructor_minishell(data);
	lstclear_exec(pipeline);
	exit(errno);
}

void	ft_builtin_print_error(char *builtin, char *name, char *str_error)
{
	ft_putstr_fd(PREFIX_ERROR, 2);
	if (builtin)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(builtin, 2);
	}
	if (name)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(name, 2);
	}
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(str_error, 2);
	ft_putstr_fd("\n", 2);
}

void	ft_unset_builtin_print_error(char *builtin, char *name, char *str_error)
{
	ft_putstr_fd(PREFIX_ERROR, 2);
	if (builtin)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(builtin, 2);
	}
	if (name)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd("`", 2);
		ft_putstr_fd(name, 2);
		ft_putstr_fd("'", 2);
	}
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(str_error, 2);
	ft_putstr_fd("\n", 2);
}
