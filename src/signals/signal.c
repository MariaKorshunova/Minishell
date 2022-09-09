/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 01:21:26 by refrain           #+#    #+#             */
/*   Updated: 2022/09/09 05:10:39 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ctrlc_handler(void)
{
	int	pid;

	pid = waitpid(-1, NULL, WNOHANG);
	if (!pid)
		write(1, "\n", 1);
	if (pid)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

int	signal_handler(t_data *data)
{
	(void)data;
	signal(SIGINT, (void *)ctrlc_handler);
	signal(SIGQUIT, SIG_IGN);
	return (0);
}
