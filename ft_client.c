/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 00:17:13 by jikarunw          #+#    #+#             */
/*   Updated: 2023/10/21 01:00:34 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_response;

void	ft_feedback_handle(int sig)
{
	if (sig == SIGUSR1)
		g_response = 1;
}

void	ft_wait_for_feedback(void)
{
	if (g_response == 0)
		pause();
	g_response = 0;
}

void	convert_char_to_bits(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				print_error("Error in sending Signal");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				print_error("Error in sending Signal");
		}
		ft_wait_for_feedback();
		i--;
	}
}

int	main(int argc, char *argv[])
{
	int		server_pid;
	char	*str;

	str = NULL;
	if (argc != 3 || (!(argv[2])))
		print_error("Error in arguments");
	else
	{
		server_pid = ft_atoi(argv[1]);
		if (server_pid <= 0)
			print_error("Error in PID");
		str = argv[2];
	}
	while (*str)
	{
		convert_char_to_bits(*str, server_pid);
		str++;
	}
	convert_char_to_bits(server_pid, *str);
	return (0);
}
