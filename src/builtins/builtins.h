/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:02:52 by refrain           #+#    #+#             */
/*   Updated: 2022/08/29 19:06:23 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <unistd.h>
# include <stdlib.h> 
# include <stdio.h>
# include "../../libft/libft.h"
# include "../../include/minishell.h"

void	find_builtin(char **cmd, t_data *data);
int		ft_echo(char **cmd);
int		ft_pwd(void);
int	    ft_cd(char **cmd, t_data *data);
int	    ft_env(t_data *data);
int		ft_strcmp(const char *s1, const char *s2);
int     pos_in_envp(t_data *data, char *str);
char	*get_value_from_envp(t_data *data, char *str);
int     put_envp_value(t_data *data, char *key, char *new);
char	**ft_example(void);

#endif