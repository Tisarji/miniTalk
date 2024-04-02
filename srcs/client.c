/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 00:17:13 by jikarunw          #+#    #+#             */
/*   Updated: 2024/03/31 16:06:47 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send(int pid, char *msg)
{
	int	i;
	int	j;
	int	sig;
	int	msg_len;

	i = 0;
	msg_len = ft_strlen(msg);
	while (i <= msg_len)
	{
		j = -1;
		while (++j < 8) {
			sig = SIGUSR1;
			if (msg[i] << j & 0b10000000)
				sig = SIGUSR2;
			if (kill(pid, sig))
			{
				ft_printf("Error sending signal. \n");
				exit(EXIT_FAILURE);
			}
			usleep(100);
		}
		i++;
	}
}

void	handle_sig_client(int sig)
{
	(void) sig;
	ft_printf("client | Message sent.\n");
	exit(0);
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("client | Incorrect number of arguments.\n");
		return (EXIT_FAILURE);
	}
	if (signal(SIGUSR1, handle_sig_client) == SIG_ERR)
	{
		printf("server | Failed adding signal handler.\n");
		return (EXIT_SUCCESS);
	}
	send(ft_atoi(argv[1]), argv[2]);
	if (sleep(ft_strlen(argv[2]) + 1) == 0)
	{
		printf("client | Message timed out.\n");
		return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}
