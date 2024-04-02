/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:57:30 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/31 21:56:24 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include <signal.h>
# include <unistd.h>
# include <stdbool.h>

void	handle_sig(int sig);
void	send(int pid, char *msg);
char	*addchar(char *str, char chr, int *str_len);
void	handle_sig_server(int sig, siginfo_t *info, void *uctx);
void	handle_sig_client(int sig);

#endif
