/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 03:11:50 by refrain           #+#    #+#             */
/*   Updated: 2022/09/19 17:55:22 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static	void	ft_swap(char **lhs, char **rhs)
{
	char	*tmp;

	tmp = *lhs;
	*lhs = *rhs;
	*rhs = tmp;
}

void	ft_bubble_sort(char **arr)
{
	int	i;
	int	j;
	int	size;

	size = 0;
	while (*(arr + size) != NULL)
		size++;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (ft_strcmp(arr[j], arr[j + 1]) > 0)
				ft_swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

void	ft_print_sorted_array(char *str)
{
	int	i;
	int	i_pos;

	i = 0;
	i_pos = ft_strchr_pos(str, '=');
	printf("declare -x ");
	if (i_pos == -1)
		printf("%c\n", str[i++]);
	else
	{
		while (str[i] != '=')
			printf("%c", str[i++]);
		printf("%c", str[i++]);
		printf("\"");
		while (str[i])
			printf("%c", str[i++]);
		printf("\"\n");
	}
}

int	ft_export(char **cmd, t_data *data)
{
	int		i;
	int		j;
	// char	*newval;

	i = 0;
	if (!cmd[1])
	{
		ft_bubble_sort(data->env_arr);
		while (data->env_arr && (data->env_arr)[i])
			ft_print_sorted_array((data->env_arr)[i++]);
	}
	i = 1;
	while (cmd && cmd[i])
	{
		j = 0;
		while (cmd[i][j] != '=' && cmd[i][j] != '\0')
			j++;
		if (add_lst_env(&(data->env), cmd[i], j))
			return (-1);
		i++;
	}
	data->exit_status = 0;
	return (data->exit_status);
}
