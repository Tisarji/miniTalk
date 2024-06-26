/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikarunw <jikarunw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 00:17:13 by jikarunw          #+#    #+#             */
/*   Updated: 2024/04/02 14:02:40 by jikarunw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	g_bit_handler;

void	validation_server(int signo)
{
	if (signo == SIGUSR2)
		exit(EXIT_SUCCESS);
	else if (signo == SIGUSR1)
		g_bit_handler = 1;
}

int	check_av(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3 || !av[2][0])
	{
		ft_putstr_fd("Error arguments, please try again.\n", 2);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(av[1]);
	if (pid == -1)
	{
		ft_putstr_fd("Error: PID -1 is reserved for the kernel.\n", 2);
		exit(EXIT_FAILURE);
	}
	i = -1;
	while (av[1][++i])
	{
		if (!(ft_isdigit(av[1][i])) || pid < 0)
		{
			ft_putstr_fd("Error: a PID only has positive decimal numbers.", 2);
			exit(EXIT_FAILURE);
		}
	}
	return (pid);
}

void	send_bit(int pid, char c)
{
	int	bit;

	bit = __CHAR_BIT__ * sizeof(c) - 1;
	while (bit >= 0)
	{
		g_bit_handler = 0;
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit--;
		while (g_bit_handler != 1)
			usleep(100);
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	pid = check_av(ac, av);
	i = -1;
	signal(SIGUSR1, validation_server);
	signal(SIGUSR2, validation_server);
	while (av[2][++i])
		send_bit(pid, av[2][i]);
	send_bit(pid, '\n');
	send_bit(pid, 0);
	while (1)
		pause();
}
