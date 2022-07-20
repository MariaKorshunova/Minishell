/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:53:33 by jmabel            #+#    #+#             */
/*   Updated: 2022/07/20 17:37:25 by jmabel           ###   ########.fr       */
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

/* struct for list key-value */
typedef struct s_key_value
{
	void				*key;
	void				*value;
	struct s_key_value	*next;
}	t_key_value;

/* Struct with common var in minishell */
typedef struct s_data
{
	t_key_value	*env;
	int			exit_flag;
}	t_data;

#endif