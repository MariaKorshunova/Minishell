/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 01:21:26 by refrain           #+#    #+#             */
/*   Updated: 2022/08/15 03:46:38 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signal_handler.h"

//SIGINT - symbol name for Ctrl+C (displays a new prompt on a new line)
//SIGQUIT - symbol name for Ctrl+\ (does nothing)
//SIG_IGN — igrores the signal, specified as signo

void	ctrlc_handler(int signum)
{
	if (signum == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

int	signal_handler(void)
{
	signal(SIGINT, ctrlc_handler);
	signal(SIGQUIT, SIG_IGN);
	return (0);
}
