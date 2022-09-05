/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 23:22:23 by refrain           #+#    #+#             */
/*   Updated: 2022/08/29 20:48:05 by refrain          ###   ########.fr       */
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

// char	**ft_example(void)
// {
// 	char	**str;

// 	str = (char **)malloc (4 * sizeof(char *));
// 	str[0] = ft_strdup("pwd");
// 	str[1] = ft_strdup(" test");
// 	str[2] = ft_strdup(" new");
// 	str[3] = NULL;
// 	return (str);
// }

// int	main(void)
// {
// 	char **str = ft_example();
// 	t_data *data = NULL;
// 	find_builtin(str, data);
// 	free_2dimensional_array((void **)str);
// 	return (0);
// }

