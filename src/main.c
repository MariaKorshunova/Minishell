/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:47:54 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/07 21:45:54 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_data(t_data *data);

int	main(int argc, char **argv, char **envp)
{
	char	*prompt;
	t_data	data;

	(void) argc;
	(void) argv;
	init_data(&data);
	if (pars_envp(&data, envp))
		return (EXIT_FAILURE);
	signal_handler();
	while (data.exit_flag)
	{
		prompt = readline(PROMPT);
		if (!prompt)
		{
			printf("exit\n");
			destructor_minishell(&data);
			return (EXIT_FAILURE);
		}
		if (execution(&data, prompt))
		{
			free(prompt);
			destructor_minishell(&data);
			return (EXIT_FAILURE);
		}
		free(prompt);
	}
	destructor_minishell(&data);
	return (EXIT_SUCCESS);
}

static void	init_data(t_data *data)
{
	data->env = NULL;
	data->env_arr = NULL;
	data->bin_path = NULL;
	data->change_env = 0;
	data->exit_status = 0;
	data->exit_flag = 1;
}	
