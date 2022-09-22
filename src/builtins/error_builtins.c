/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 20:32:07 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/19 20:32:44 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

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

void	ft_export_unset_print_error(char *builtin, char *name, char *str_error)
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
