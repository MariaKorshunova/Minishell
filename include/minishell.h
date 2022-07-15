/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:53:33 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/15 11:15:27 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h> 
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include "parser.h"

/* struct for environment */
typedef struct s_env
{
	char			*name;
	char			*content;
	struct s_env	*next;
}	t_env;

/* Struct with common var in minishell */
typedef struct s_data
{
	t_env	*env;
}	t_data;

#endif