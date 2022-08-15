/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: refrain <refrain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 03:26:38 by refrain           #+#    #+#             */
/*   Updated: 2022/08/15 03:52:47 by refrain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_H
# define SIGNAL_H

# include "signal.h"
# include "stdio.h"
# include <readline/readline.h>

void	ctrlc_handler(int signum);
int		signal_handler(void);

#endif