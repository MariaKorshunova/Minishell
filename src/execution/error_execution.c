/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 20:18:09 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/21 19:47:03 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	ft_print_error(char *name, char *str_error)
{
	ft_putstr_fd(PREFIX_ERROR, 2);
	if (name)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(name, 2);
	}
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(str_error, 2);
	ft_putstr_fd("\n", 2);
}

void	ft_error_child_process(t_data *data, t_exec **pipeline)
{
	destructor_minishell(data);
	lstclear_exec(pipeline);
	exit(errno);
}

void	ft_error_read_prompt(t_data *data)
{
	printf("exit\n");
	destructor_minishell(data);
	exit (EXIT_FAILURE);
}

void	ft_error_execution(t_data *data, char *prompt)
{
	printf("exit\n");
	free(prompt);
	destructor_minishell(data);
	exit (EXIT_FAILURE);
}
