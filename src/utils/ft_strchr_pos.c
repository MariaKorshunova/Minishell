/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:35:57 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/14 14:07:51 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strchr_pos(char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (-1);
	str = (char *)s;
	while (str[i] != '\0' && str[i] != (char)c)
		i++;
	if (str[i] != (char)c)
		return (-1);
	else
		return (i);
}

int	ft_strrchr_pos(char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (c == '\0')
		return (i);
	while (i > 0)
	{
		i--;
		if (s[i] == (char)c)
			return (i);
	}
	return (i);
}
