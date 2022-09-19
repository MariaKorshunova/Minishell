/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 23:22:23 by refrain           #+#    #+#             */
/*   Updated: 2022/09/14 15:04:55 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	ft_pwd(void)
{
	char	*buf;
	char	*pwd;
	t_data	data;

	buf = NULL;
	pwd = getcwd(buf, 0);
	if (pwd)
		printf("%s\n", pwd);
	else
		return (-1);
	free (pwd);
	data.exit_status = 0;
	return (data.exit_status);
}
