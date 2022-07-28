/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_list_to_chararray.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:11:26 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/25 17:57:29 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*strjoin_envp_key_value(char *s1, char *s2);

int	envp_list_to_chararray(t_data *data)
{
	int			size_arr;
	int			i;
	t_key_val	*tmp;

	size_arr = lst_size_key_value(data->env);
	tmp = data->env;
	i = 0;
	free_2dimensional_array((void **)data->env_arr);
	data->env_arr = (char **)malloc((size_arr + 1) * sizeof(char *));
	if (!data->env_arr)
		return (EXIT_FAILURE);
	while (i < size_arr)
	{
		data->env_arr[i] = strjoin_envp_key_value(tmp->key, tmp->value);
		if (!data->env_arr[i])
		{
			free_2dimensional_array((void **)data->env_arr);
			return (EXIT_FAILURE);
		}
		tmp = tmp->next;
		i++;
	}
	data->env_arr[i] = NULL;
	return (EXIT_SUCCESS);
}

static char	*strjoin_envp_key_value(char *s1, char *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	dest = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '=';
	j = i + 1;
	i = 0;
	while (i < ft_strlen(s2))
		dest[j++] = s2[i++];
	dest[j] = '\0';
	return (dest);
}
