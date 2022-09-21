/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_without_arg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 02:04:52 by refrain           #+#    #+#             */
/*   Updated: 2022/09/21 16:44:52 by refrain          ###   ########.fr       */
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

static void	ft_bubble_sort(char **arr)
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

static void	print_util(char *str, int i)
{
	printf("%c", str[i++]);
	printf("\"");
	while (str[i])
		printf("%c", str[i++]);
	printf("\"\n");
}

static int	ft_print_sorted_array(t_data *data, char *str)
{
	int		i;
	int		i_pos;
	char	*name;

	i = 0;
	i_pos = ft_strchr_pos(str, '=');
	name = ft_substr(str, 0, i_pos);
	if (!name)
		return (EXIT_FAILURE);
	printf("declare -x ");
	while (str[i] != '=')
	{
		printf("%c", str[i++]);
		if (str[i] == '+')
			i++;
	}
	if (!key_value_search_with_key(data->env, name))
	{
		printf("\n");
		return (EXIT_SUCCESS);
	}
	print_util(str, i);
	free (name);
	return (EXIT_SUCCESS);
}

int	export_without_args(t_data *data)
{
	int		i;

	i = 0;
	ft_bubble_sort(data->env_arr);
	while (data->env_arr && (data->env_arr)[i])
		ft_print_sorted_array(data, (data->env_arr)[i++]);
	return (0);
}
