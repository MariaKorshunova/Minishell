/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:24:23 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/22 20:52:37 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			pars_envp(t_data *data, char **envp);
static int	pars_envp_lst(t_key_val **lst, char **envp);
static int	add_lst_env(t_key_val **lst, char *str, int j);
static char	*pars_name_envp(char *str, int j, t_key_val	**lst);
static char	*pars_value_envp(char *str, int j, t_key_val **lst, char *name);

/* in progress */

int	pars_envp(t_data *data, char **envp)
{
	if (pars_envp_lst(&data->env, envp))
		return (EXIT_FAILURE);
	lstprint_key_value(data->env);
	return (EXIT_SUCCESS);
}

static int	pars_envp_lst(t_key_val **lst, char **envp)
{
	int			i;
	int			j;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] != '=' && envp[i][j] != '\0')
			j++;
		if (add_lst_env(lst, envp[i], j))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	add_lst_env(t_key_val **lst, char *str, int j)
{
	t_key_val	*lstnew;
	char		*name;
	char		*value;

	name = pars_name_envp(str, j, lst);
	value = NULL;
	if (!name)
		return (EXIT_FAILURE);
	if (str[j] != '\0')
	{
		value = pars_value_envp(str, j, lst, name);
		if (!value)
			return (EXIT_FAILURE);
	}
	lstnew = lstnew_key_value(name, value);
	if (!lstnew)
	{
		free(name);
		free(value);
		lstclear_key_value(lst);
		return (EXIT_FAILURE);
	}
	lstadd_back_key_value(lst, lstnew);
	return (EXIT_SUCCESS);
}

static char	*pars_name_envp(char *str, int j, t_key_val	**lst)
{
	char	*name;

	name = ft_substr(str, 0, j);
	if (!name)
	{
		lstclear_key_value(lst);
		return (NULL);
	}
	return (name);
}

static char	*pars_value_envp(char *str, int j, t_key_val **lst, char *name)
{
	char		*value;

	value = ft_substr(str, j + 1, ft_strlen(str) - j - 1);
	if (!value)
	{
		free(name);
		lstclear_key_value(lst);
		return (NULL);
	}
	return (value);
}
