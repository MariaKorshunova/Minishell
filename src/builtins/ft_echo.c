/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:58:46 by refrain           #+#    #+#             */
/*   Updated: 2022/08/15 05:06:46 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	if (s)
// 	{
// 		while (s[i] != '\0')
// 			i++;
// 		return (i);
// 	}
// 	return (0);
// }

// char	*ft_strdup(const char *s1)
// {
// 	size_t	i;
// 	size_t	size;
// 	char	*dest;

// 	i = 0;
// 	size = ft_strlen(s1);
// 	dest = (char *)malloc((size + 1) * sizeof(char));
// 	if (dest == NULL)
// 		return (NULL);
// 	while (s1[i])
// 	{
// 		dest[i] = s1[i];
// 		i++;
// 	}
// 	dest[i] = '\0';
// 	return (dest);
// }

// int	ft_isspace(int c)
// {
// 	if ((c >= 9 && c <= 13) || c == 32)
// 		return (1);
// 	return (0);
// }

// char	**ft_example(void)
// {
// 	char	**str;

// 	str = (char **)malloc (11 * sizeof(char *));
// 	str[0] = ft_strdup("echo");
// 	str[1] = ft_strdup("-n");
// 	str[2] = ft_strdup("-n");
// 	str[3] = ft_strdup("-n");
// 	str[4] = ft_strdup("hello");
// 	str[5] = ft_strdup(" world");
// 	str[6] = ft_strdup(" world ");
// 	str[7] = ft_strdup(" -n");
// 	str[8] = ft_strdup(" -n");
// 	str[9] = ft_strdup(" yesy");
// 	str[10] = ft_strdup(" -n");
// 	return (str);
// }

// int	ft_strcmp(const char *s1, const char *s2)
// {
// 	int	i;

// 	i = 0;
// 	if (!s1 && !s2)
// 		return (0);
// 	if (!s1 || !s2)
// 		return (-1);
// 	while (s1[i] != '\0' && s2[i] != '\0' )
// 	{
// 		if (s1[i] != s2[i])
// 			return (s1[i] - s2[i]);
// 		i++;
// 	}
// 	if (s1[i] != '\0' || s2[i] != '\0')
// 		return (-1);
// 	return (0);
// }

int	ft_echo(char **cmd)
{
	int		i;
	int		flag;

	i = 1;
	flag = 0;
	if (cmd[i] && ft_strcmp(cmd[i], "-n") == 0)
	{
		flag = 1;
		i = 2;
	}
	while (cmd && cmd[i])
	{
		if (ft_strcmp(cmd[i], "-n") == 0)
			i++;
		else
		{
			printf("%s", cmd[i++]);
			while(cmd && cmd[i])
				printf("%s", cmd[i++]);
		}
	}
	if (flag == 0)
		printf("\n");
	return (0);
}

// int	main(void)
// {
// 	char **str = ft_example();
// 	t_key_val	*envp_list = NULL;
// 	find_builtin(str, envp_list);
// 	return (0);
// }
