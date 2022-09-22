/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 03:26:38 by refrain           #+#    #+#             */
/*   Updated: 2022/09/22 07:11:42 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_HANDLER_H
# define SIGNAL_HANDLER_H

# include "minishell.h"

int		signal_handler(t_data *data);
void	signal_handler_child(t_data *data);
void	signal_handler_heredoc(void);

#endif