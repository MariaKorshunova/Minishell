/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 00:15:07 by refrain           #+#    #+#             */
/*   Updated: 2022/09/19 21:01:30 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char	*ft_cut_string(char *str)
{
	int		i;
	char	*newvalue;

	i = ft_strlen(str);
	while (str[i] != '/')
		i--;
	newvalue = ft_substr(str, 0, i + 1);
	if (!newvalue)
		return (NULL);
	return (newvalue);
}
