/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 17:02:52 by refrain           #+#    #+#             */
/*   Updated: 2022/09/21 18:27:43 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

int			find_builtin(char **cmd, t_data *data);
int			ft_exit(char **cmd, t_data *data);
int			ft_echo(char **cmd);
int			ft_pwd(void);
int			ft_cd(char **cmd, t_data *data);
int			ft_chdir(char *path, char **cmd);
int			ft_env(t_data *data);
int			home_directory(char **cmd, char *home);
int			change_dir(char **cmd, char *home, char *pwd, char *oldpwd);
int			lst_addback_new_key_value(t_key_val **lst, char *key, char *value);
int			ft_unset(char **cmd, t_data *data);
int			ft_export(char **cmd, t_data *data);
int			export_without_args(t_data *data);
int			ft_check_arg(char **cmd);
int			ft_export_join(char **cmd, t_data *data, int i);
int			add_val_to_export(t_data *data, char *newkey, char *newvalue);
int			ft_malloc_error(char *name);

char		*ft_cut_string(char *str);
char		*find_new_value(char **cmd, char *newkey, int i);
char		*find_new_key(char **cmd, int i);
char		*find_key(t_key_val *env, char	*key);

void		ft_builtin_print_error(char *builtin, char *name, char *str_error);
void		ft_export_unset_print_error(char *builtin, char *name,
				char *str_error);

#endif