/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:47:54 by jmabel            #+#    #+#             */
/*   Updated: 2022/09/22 07:07:06 by refrain          ###   ########.fr       */
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
	{
		perror(PREFIX_ERROR);
		return (EXIT_FAILURE);
	}
	signal_handler(&data);
	while (data.exit_flag)
	{
		prompt = readline(PROMPT);
		signal_handler_child(&data);
		if (!prompt)
			ft_error_read_prompt(&data);
		if (execution(&data, prompt))
			ft_error_execution(&data, prompt);
		free(prompt);
	}
	destructor_minishell(&data);
	return (data.exit_status);
}

static void	init_data(t_data *data)
{
	data->env = NULL;
	data->env_arr = NULL;
	data->bin_path = NULL;
	data->exit_status = 0;
	data->exit_flag = 1;
	data->key_tmp[0] = "TMP";
	data->key_tmp[1] = "TEMP";
	data->key_tmp[2] = "TMPDIR";
	data->key_tmp[3] = NULL;
}	
