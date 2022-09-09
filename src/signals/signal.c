/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 01:21:26 by refrain           #+#    #+#             */
/*   Updated: 2022/09/09 04:45:04 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//SIGINT - symbol name for Ctrl+C (displays a new prompt on a new line)
//SIGQUIT - symbol name for Ctrl+\ (does nothing)
//SIG_IGN — igrores the signal, specified as signo

// void	ctrlc_handler(int signum)
// {
// 	if (signum == SIGINT)
// 	{
// 		write (1, "\n", 1);
// 		rl_on_new_line();
// 		rl_replace_line("", 0);
// 		rl_redisplay();
// 	}
// }

void	ctrlc_handler(void)
{
	int	pid;

	pid = waitpid(-1, NULL, WNOHANG);
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
