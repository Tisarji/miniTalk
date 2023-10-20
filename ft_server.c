/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:00:23 by jikarunw          #+#    #+#             */
/*   Updated: 2023/10/21 00:59:37 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_signal	g_signal;

static void	ft_process_signal_data(int sig, siginfo_t *info, void *other)
{
	pid_t	client_pid;

	(void) other;
	client_pid = info->si_pid;
	if (sig == SIGUSR1)
		g_signal.current_byte = g_signal.current_byte | (1 << g_signal.bit);
	g_signal.bit--;
	if (g_signal.bit == -1)
	{
		if (g_signal.current_byte == '\0')
			ft_printf("\n");
		else
			write(1, &g_signal.current_byte, 1);
		g_signal.current_byte = 0;
		g_signal.bit = 7;
	}
	if (kill (client_pid, SIGUSR1) == -1)
		print_error("Error in sending Signal");
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	pid = getpid();
	g_signal.current_byte = 0;
	g_signal.bit = 7;
	ft_printf("PID : %d\n", pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_process_signal_data;
	if ((sigaction(SIGUSR1, &sa, NULL) == -1) \
			|| (sigaction(SIGUSR2, &sa, NULL) == -1))
		print_error("Error in sigaction");
	while (1)
		pause();
	return (0);
}
