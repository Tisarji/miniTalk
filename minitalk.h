/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:57:30 by jikarunw          #+#    #+#             */
/*   Updated: 2023/10/21 15:31:19 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/ft_printf.h"
# include <signal.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_signal
{
	int		bit;
	int		current_byte;
}	t_signal;

void	print_error(char *str);
int		ft_atoi(const char *str);

#endif
