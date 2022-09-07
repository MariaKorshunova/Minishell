/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:07:41 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/05 21:19:52 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	destructor_minishell(t_data *data)
{
	lstclear_key_value(&data->env);
	free_2dimensional_array((void **)data->env_arr);
	free_2dimensional_array((void **)data->bin_path);
}
