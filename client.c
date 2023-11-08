/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 00:17:13 by jikarunw          #+#    #+#             */
/*   Updated: 2023/11/09 00:24:42 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

bool	send(int pid, char *msg)
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
		while (++j < 8)
		{
			sig = SIGUSR1;
			if (msg[i] << j & 0b10000000)
				sig = SIGUSR2;
			if (kill(pid, sig))
				return (false);
			usleep(100);
		}
		i++;
	}
	return (true);
}

void	handle_sig(int sig)
{
	(void) sig;
	ft_printf("client | Message sent.\n");
	exit(0);
}

int	main(int ac, char **av)
{
	if (ac != 3)
		return (ft_printf("client | Incorrect number of arguments.\n"));
	if (signal(SIGUSR1, handle_sig) == SIG_ERR)
		return (ft_printf("server | Failed adding signal handler.\n"));
	if (!send(ft_atoi(av[1]), av[2]))
		return (ft_printf("client | Cannot send messages.\n"));
	if (sleep(ft_strlen(av[2]) + 1) == 0)
		return (ft_printf("client | Message timedout.\n"));
}
