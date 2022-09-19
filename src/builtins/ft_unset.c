/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:01:54 by refrain           #+#    #+#             */
/*   Updated: 2022/09/19 20:08:16 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

// void	ft_remove_env()
// {
// 	int	i;

// 	i = 
// }

// int	ft_is_valid()
// {
// }

int	test_find_lst_key_value(t_key_val *lst, char *value)
{
	t_key_val	*temp;

	while (lst && lst->next)
	{
		temp = lst;
		if (!ft_strcmp(value, temp->key))
		{
			free((char *)temp->key);
			free((char *)temp->value);
			return (0);
		}
		temp = temp->next;
	}
	return (1);
}

t_key_val	*find_lst_key_value(t_key_val *lst, char *value)
{
	while (lst && lst->next)
	{
		if (!ft_strcmp(value, lst->key))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	lst_delete_key_value(t_key_val **lst, t_key_val *new, char *value)
{
	t_key_val	*tmp;

	if (!new || !lst || !value)
		return ;
	tmp = new;
	if (tmp)
	{
		free (tmp->key);
		free (tmp->value);
		free (tmp);
	}
}

int	ft_unset(char **cmd, t_key_val *data)
{
	// char		*value;
	// int			i;
	t_key_val	*temp;

	// i = 1;
	temp = find_lst_key_value(data, cmd[1]);
	// while (cmd && cmd[i])
	// {
	// value = key_value_search_with_key(temp, cmd[i]);
	while (temp)
	{
		if (!ft_strcmp(cmd[1], (char *)temp->key))
		{
			printf("key %s\n value %s\n", (char *)temp->key, (char *)temp->value);
			if (find_lst_key_value(data, cmd[1]))
				return (-1);
			// lst_delete_key_value(&data, temp, cmd[1]);
			// free((char *)temp->value);
			// free((char *)temp->key);
			break ;
		}
		temp = temp->next;
	}
	
		// if (!ft_is_valid(cmd[i]))
		// {
			ft_export_unset_print_error(cmd[0], cmd[1], "not a valid identifier");
		// 	data->exit_status = 1;
		// }
		// i++;
	
	// data->exit_status = 0;
	return (0);
}
