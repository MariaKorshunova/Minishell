/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 23:22:23 by refrain           #+#    #+#             */
/*   Updated: 2022/08/15 01:16:25 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_pwd(void)
{
	char	*buf;
	char	*pwd;

	buf = NULL;
	pwd = getcwd(buf, 0);
	if (pwd)
		printf("%s\n", pwd);
	else
		return (-1);
	free (pwd);
	return (0);
}

// int	main(void)
// {
// 	ft_pwd();
// 	return (0);
// }

char	**ft_example(void)
{
	char	**str;

	str = (char **)malloc (12 * sizeof(char *));
	str[0] = ft_strdup("pwd");
	str[1] = ft_strdup(" test");
	str[2] = ft_strdup(" new");
	return (str);
}

int	main(void)
{
	char **str = ft_example();
	t_key_val	*envp_list = NULL;
	find_builtin(str, envp_list);
	return (0);
}

