/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 00:15:07 by refrain           #+#    #+#             */
/*   Updated: 2022/09/07 04:13:03 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char	*ft_cut_string(char *str)
{
	int		i;
	char	*new_str;

	if (!str)
		return (NULL);
	i = ft_strlen(str);
	while (str[i] != '/')
		i--;
	new_str = ft_substr(str, 0, i + 1);
	return (new_str);
}
