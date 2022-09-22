/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_init_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:59:22 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/19 22:07:10 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	init_add(t_key_val **env, char *name, char *value);
static int	init_shell_level(t_key_val **env);

int	change_init_env(t_key_val **env)
{
	if (!key_value_search_with_key(*env, "OLDPWD"))
	{
		if (lst_addback_new_key_value(env, "OLDPWD", NULL))
			return (EXIT_FAILURE);
	}
	if (init_add(env, "SHELL", NAME))
		return (EXIT_FAILURE);
	if (init_shell_level(env))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	init_add(t_key_val **env, char *name, char *value)
{
	if (key_value_search_with_key(*env, name))
	{
		if (ft_put_new_value(*env, name, value))
			return (EXIT_FAILURE);
	}
	else
	{
		if (lst_addback_new_key_value(env, name, value))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	init_shell_level(t_key_val **env)
{
	int		level;
	char	*char_level;
	char	*new_level;

	char_level = key_value_search_with_key(*env, "SHLVL");
	if (!char_level)
		level = 1;
	else
		level = ft_atoi(char_level) + 1;
	new_level = ft_itoa(level);
	if (!new_level)
		return (EXIT_FAILURE);
	if (init_add(env, "SHLVL", new_level))
	{
		free(new_level);
		return (EXIT_FAILURE);
	}
	free(new_level);
	return (EXIT_SUCCESS);
}
