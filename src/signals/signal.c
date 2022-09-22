/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 01:21:26 by refrain           #+#    #+#             */
/*   Updated: 2022/09/22 07:11:11 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ctrlc_handler(void)
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

static void	slash_handler_util(int signal)
{
	int		pid;

	pid = waitpid(-1, NULL, WNOHANG);
	if (signal == SIGQUIT)
	{
		write(1, "Quit: 3\n", 9);
	}
	if (signal == SIGINT)
	{
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
}

void	signal_handler_child(t_data *data)
{
	if (data->child)
	{
		if (signal(SIGQUIT, (void *)slash_handler_util) != SIG_ERR)
				data->exit_status = 131;
		if (signal(SIGINT, (void *)slash_handler_util) != SIG_ERR)
				data->exit_status = 130;
	}
}

void	signal_handler_heredoc(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, (void *)slash_handler_util);
}

int	signal_handler(t_data *data)
{
	(void)data;
	signal(SIGINT, (void *)ctrlc_handler);
	signal(SIGQUIT, SIG_IGN);
	return (0);
}
