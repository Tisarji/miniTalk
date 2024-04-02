/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:57:30 by jikarunw          #+#    #+#             */
/*   Updated: 2024/04/02 14:04:09 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include <signal.h>
# include <unistd.h>
# include <stdbool.h>

void	print_str(char **str, unsigned long long *i, siginfo_t *info);
char	*ft_realloc(char *str, int l, char c);
void	handler_signal(int signal, siginfo_t *info, void *context);
void	validation_server(int signo);
int	check_av(int ac, char **av);
void	send_bit(int pid, char c);

#endif
