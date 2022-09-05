/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmabel <jmabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:02:52 by refrain           #+#    #+#             */
/*   Updated: 2022/09/05 22:36:52 by jmabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

void	find_builtin(char **cmd, t_data *data);
int		ft_echo(char **cmd);
int		ft_pwd(void);
int     ft_cd(char **cmd, t_data *data);
int	    ft_env(t_data *data);
void	ft_exit(char ** cmd);
// int		ft_strcmp(const char *s1, const char *s2);
int     pos_in_envp(t_data *data, char *str);
char	*get_value_from_envp(t_data *data, char *str);
int     put_envp_value(t_data *data, char *key, char *new);
char	**ft_example(void);
char	**ft_example1(void);
char	**ft_example2(void);

#endif