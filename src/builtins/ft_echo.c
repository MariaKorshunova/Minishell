/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:58:46 by refrain           #+#    #+#             */
/*   Updated: 2022/07/25 20:08:04 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

char	**ft_example(void)
{
	char	**str;

	str = (char **)malloc (3 * sizeof(char *));
	str[0] = strdup("echo");
	str[1] = strdup("-n");
	str[2] = strdup("hello");
	return (str);
}

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (-1);
	while (s1[i] != '\0' && s2[i] != '\0' )
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s1[i] != '\0' || s2[i] != '\0')
		return (-1);
	return (0);
}

void	find_builtin(const char **cmd)
{
	if (ft_strcmp((*cmd)[0], "echo") == 0)
	{
		printf("match found");
		//ft_echo(cmd);
	}
}

// int	ft_echo(char **cmd)
// {
// 	int		i;
// 	int		flag;

// 	i = 0;
// 	flag = 0;
// 	if ()
// 	while (cmd[i])
// 		printf("%s", cmd[i++]);
// 	return (0);
// }
